/*
 *
 * SmallClusterMergingAlgorithm.h header template automatically generated by a class generator
 * Creation date : ven. mars 7 2014
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


#ifndef SMALLCLUSTERMERGINGALGORITHM_H
#define SMALLCLUSTERMERGINGALGORITHM_H

#include "arborpfa/algorithm/ArborAlgorithm.h"
#include "arborpfa/algorithm/ArborAlgorithmFactory.h"


namespace arborpfa
{

	typedef std::map<pandora::Cluster*,pandora::Cluster*> ClusterToClusterMap;

/** 
 * @brief SmallClusterMergingAlgorithm class
 */ 
class SmallClusterMergingAlgorithm : public ArborAlgorithm 
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
		pandora::StatusCode Run();

		/**
			* @brief Read settings from Xml handler
			*/
		pandora::StatusCode ReadSettings(const pandora::TiXmlHandle xmlHandle);

 protected:

		/**
			*
			*/
		pandora::StatusCode GetClosestDistanceBetweenClusters(const pandora::Cluster *pCluster1, const pandora::Cluster *pCluster2, float &closestDistance);

		/**
		 *
		 */
		pandora::StatusCode GetCentroidDistanceBetweenClusters(const pandora::Cluster *pCluster1, const pandora::Cluster *pCluster2, float &distance);

	unsigned int           m_minimumClusterSizeForMerging;
	float                   m_largeDistanceClusterCut;
	bool                    m_shouldUseCentroidForClusterDistance;


}; 

inline ArborAlgorithm *SmallClusterMergingAlgorithm::Factory::CreateArborAlgorithm() const
{
	return new SmallClusterMergingAlgorithm();
}

} 

#endif  //  SMALLCLUSTERMERGINGALGORITHM_H
