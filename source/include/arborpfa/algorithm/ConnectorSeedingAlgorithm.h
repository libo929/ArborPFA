  /// \file ConnectorSeedingAlgorithm.h
/*
 *
 * ConnectorSeedingAlgorithm.h header template automatically generated by a class generator
 * Creation date : jeu. sept. 18 2014
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


#ifndef CONNECTORSEEDINGALGORITHM_H
#define CONNECTORSEEDINGALGORITHM_H

#include "arborpfa/algorithm/ArborAlgorithm.h"
#include "arborpfa/algorithm/ArborAlgorithmFactory.h"

namespace arbor
{

/** 
 * @brief ConnectorSeedingAlgorithm class
 */ 
class ConnectorSeedingAlgorithm : public ArborAlgorithm 
{
public:

/**
	* @brief Factory class for instantiating algorithm
	*/
class Factory : public ArborAlgorithmFactory
{
	public:
		ArborAlgorithm *CreateArborAlgorithm() const;
};

/**
	* @brief Run the algorithm
	*/
pandora::StatusCode RunArborAlgorithm();

/**
	* @brief Read settings from Xml handler
	*/
pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

/**
 *
 */
pandora::StatusCode ConnectWithTrackStrategy(const OrderedObjectList &orderedObjectList);

/**
 *
 */
pandora::StatusCode ConnectAll(const OrderedObjectList &orderedObjectList);

/**
 *
 */
pandora::StatusCode ConnectWithForwardObjects(Object *pObject, const OrderedObjectList &orderedObjectList);

protected:

	unsigned int         m_maxForwardPseudoLayer;
	float                 m_ecalConnectionDistance;
	float                 m_hcalConnectionDistance;
	bool                  m_allowForwardConnectionForIsolatedObjects;
	bool                  m_useOnlyTrackSeedingStrategy;
	unsigned int         m_nPseudoLayerTrackConnection;
	float                 m_trackObjectConnectionDistance;
};

//--------------------------------------------------------------------------------------------------------------------

inline ArborAlgorithm *ConnectorSeedingAlgorithm::Factory::CreateArborAlgorithm() const
{
	return new ConnectorSeedingAlgorithm();
}

} 

#endif  //  CONNECTORSEEDINGALGORITHM_H