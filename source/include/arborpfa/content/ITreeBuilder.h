  /// \file ITreeBuilder.h
/*
 *
 * ITreeBuilder.h header template automatically generated by a class generator
 * Creation date : jeu. mai 29 2014
 *
 * This file is part of ArborPFA libraries.
 * 
 * ArborPFA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * ArborPFA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with ArborPFA.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Ete Remi
 * @copyright CNRS , IPNL
 */


#ifndef ITREEBUILDER_H
#define ITREEBUILDER_H

#include "Pandora/StatusCodes.h"
#include "Helpers/XmlHelper.h"

#include "arborpfa/arbor/ArborTypes.h"
#include "arborpfa/arbor/Arbor.h"

namespace arbor
{

class Tree;
class Object;

/** 
 * @brief ITreeBuilder class. </br>
 * Main interface for building a tree from a seed object. </br>
 * Suppose also that this seed is already connected to other object
 * so that a tree can be built from this seed
 */ 
class ITreeBuilder 
{
 protected:

	/**
	 * @brief Dtor
	 */
	virtual ~ITreeBuilder() {}

	/**
	 * @brief Build a tree from a seed object. Tree object must be allocated by the user
	 */
	virtual pandora::StatusCode Build(Object *pSeedObject, ObjectList &treeObjectList) = 0;

	/**
	 * @brief Read settings if needed
	 */
 virtual pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle)
 {
 	/* nop */
 	return pandora::STATUS_CODE_SUCCESS;
 }

 private:

	/**
	 *
	 */
	const Arbor *GetArbor() const;

	/**
	 *
	 */
	const ArborContentApiImpl *GetArborContentApiImpl() const;

	/**
		*
		*/
	pandora::StatusCode RegisterArbor(Arbor *pArbor);


	Arbor     *m_pArbor;          ///< The arbor instance to run this the tree builder

	friend class Arbor;
	friend class ArborPluginManager;
	friend class Tree;
};


inline const Arbor *ITreeBuilder::GetArbor() const
{
	if(NULL == m_pArbor)
		throw pandora::StatusCodeException(pandora::STATUS_CODE_NOT_INITIALIZED);

	return m_pArbor;
}



inline const ArborContentApiImpl *ITreeBuilder::GetArborContentApiImpl() const
{
	if(NULL == m_pArbor)
		throw pandora::StatusCodeException(pandora::STATUS_CODE_NOT_INITIALIZED);

	return m_pArbor->GetArborContentApiImpl();
}



inline pandora::StatusCode ITreeBuilder::RegisterArbor(Arbor *pArbor)
{
	if(NULL == pArbor)
		return pandora::STATUS_CODE_FAILURE;

	m_pArbor = pArbor;

	return pandora::STATUS_CODE_SUCCESS;
}

} 

#endif  //  ITREEBUILDER_H