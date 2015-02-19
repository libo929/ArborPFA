  /// \file Object.h
/*
 *
 * Object.h header template automatically generated by a class generator
 * Creation date : mar. juin 3 2014
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
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef OBJECT_H
#define OBJECT_H

// arbor
#include "arborpfa/content/IConnectable.h"
#include "arborpfa/arbor/ArborTypes.h"

// pandora
#include "Pandora/StatusCodes.h"
#include "Pandora/PandoraInputTypes.h"
#include "Objects/CartesianVector.h"

namespace pandora
{
 template<typename T> class AlgorithmObjectManager;
}

namespace arbor
{
//class ObjectManager;
/** 
 * @brief Object class
 */ 
class Object : public IConnectable
{
public:

 // Inherited from IConnectable interface
	virtual bool IsConnectedWith(Object *pObject) const;
	virtual const ConnectorList &GetConnectorList() const;
	virtual const ConnectorList &GetBackwardConnectorList() const;
	virtual const ConnectorList &GetForwardConnectorList() const;
	virtual bool IsBackwardConnector(const Connector *pConnector) const;
	virtual bool IsForwardConnector(const Connector *pConnector) const;
	virtual pandora::StatusCode FindConnector(const Object *pObject, Connector *&pConnector) const;
	virtual bool IsConnected() const;
	virtual pandora::StatusCode ConnectWith(Object *pObject, ConnectorDirection direction, float weight = 1.0);
	virtual pandora::StatusCode ConnectWith(Object *pObject, ConnectorDirection direction, Connector *&pConnector, float weight = 1.0);
	virtual pandora::StatusCode RemoveConnectionWith(Object *pObject);
	virtual pandora::StatusCode RemoveAllConnections();
	virtual pandora::StatusCode SetCurrentBackwardConnector(Connector *pConnector);
	virtual Connector *GetCurrentBackwardConnector() const;

	/**
	 * @brief Get the position of the object
	 */
	virtual const pandora::CartesianVector &GetPosition() const;

	/**
	 * @brief Return the granularity of the object
	 */
	virtual pandora::Granularity GetGranularity() const;

	/**
	 * @brief Returns the object type (ECAL, HCAL, MUON, etc...)
	 */
	virtual pandora::HitType GetObjectType() const;

	/**
	 * @brief Return the pseudo-layer associated to this object
	 */
	virtual pandora::PseudoLayer GetPseudoLayer() const;

	/**
	 *
	 */
	virtual const pandora::CaloHitList &GetCaloHitList() const;

	/**
	 *
	 */
	virtual bool IsSingleCaloHitObject() const;

	/**
	 *
	 */
	virtual pandora::StatusCode AddCaloHit(pandora::CaloHit *pCaloHit);

	/**
	 *
	 */
	virtual pandora::StatusCode RemoveCaloHit(pandora::CaloHit *pCaloHit);

	/**
	 *
	 */
	virtual bool Contains(const pandora::CaloHit *pCaloHit) const;

	/**
	 *
	 */
	virtual pandora::StatusCode SetFlag(ObjectTagFlag tagFlag, bool flag);

	/**
	 *
	 */
	virtual bool GetFlag(ObjectTagFlag flag) const;

	/**
	 * @brief Sort the object by increasing position. Used for std::sort
	 */
	static bool SortByFromInnermostPseudoLayer(Object *pObj1, Object *pObj2);


protected:

	/**
		* @brief Ctor
		*/
	Object(pandora::CaloHit *pCaloHit);

	/**
		* @brief Dtor
		*/
	virtual ~Object();


	// members
	pandora::CaloHitList            m_caloHitList;
	ObjectMetaData                 *m_pMetaData;
 pandora::CartesianVector        m_position;            								   ///< The position of this object
 pandora::Granularity            m_granularity;                   ///< the granularity of the object
 pandora::PseudoLayer            m_pseudoLayer;                   ///< The associated pseudo layer
 pandora::HitType                m_objectType;                    ///< The associated object type
 TagFlagMap                      m_tagFlagMap;                    ///< The tag flag map

	// friendship class
	friend class ObjectManager;
	friend class ReclusterMetaData;
	friend class pandora::AlgorithmObjectManager<arbor::Object>;
};

} 

#endif  //  OBJECT_H
