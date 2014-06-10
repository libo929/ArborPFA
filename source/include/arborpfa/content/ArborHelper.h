/*
 *
 * ArborHelper.h header template automatically generated by a class generator
 * Creation date : lun. mars 10 2014
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


#ifndef ARBORHELPER_H
#define ARBORHELPER_H

// pandora
#include "Pandora/StatusCodes.h"
#include "Objects/CartesianVector.h"
#include "Helpers/ClusterHelper.h"

// std
#include <utility>
#include <cstddef>

#include "arborpfa/arbor/ArborTypes.h"

namespace pandora
{
 class Cluster;
 class CartesianVector;
}

namespace arbor
{

class Object;
class Connector;

/** 
 * @brief ArborHelper class. </br>
 * Provide helpful tools for the arbor algorithm
 */ 
class ArborHelper 
{
 public:

		/**
			* @brief Compute the centroid (barycenter) of the cluster.
			*
			* @param pCluster the cluster for centroid computation
			* @param centroid the centroid position to receive (by reference)
			*/
	 static pandora::StatusCode GetCentroid(const pandora::Cluster *pCluster, pandora::CartesianVector &centroid);

	 /**
	  * @brief Compute the distance wrt the cluster centroids. See ArborHelper::GetCentroid() method
	  *
	  * @param pCluster1 the first cluster
	  * @param pCluster2 the second cluster
	  * @param the distance between centroid to receive (by reference)
	  */
	 static pandora::StatusCode GetCentroidDifference(const pandora::Cluster *pCluster1, const pandora::Cluster *pCluster2, float &centroidDifference);

	 /**
	  * @brief Return the distance of closest approach of the two clusters, i.e, the </br>
	  * minimum distance between their calo hits
	  *
	  * @param pCluster1 the first cluster
	  * @param pCluster2 the second cluster
	  * @param distance the distance of closest approach to receive (by reference)
	  */
	 static pandora::StatusCode GetClosestDistanceApproach(const pandora::Cluster *pCluster1, const pandora::Cluster *pCluster2, float &distance);

		/**
			* @brief Compute the centroid (barycenter) of the cluster.
			*
			* @param pCluster the cluster for centroid computation
			* @param centroid the centroid position to receive (by reference)
			*/
	 static pandora::StatusCode GetCentroid(const arbor::Cluster *pCluster, pandora::CartesianVector &centroid);

	 /**
	  * @brief Compute the distance wrt the cluster centroids. See ArborHelper::GetCentroid() method
	  *
	  * @param pCluster1 the first cluster
	  * @param pCluster2 the second cluster
	  * @param the distance between centroid to receive (by reference)
	  */
	 static pandora::StatusCode GetCentroidDifference(const arbor::Cluster *pCluster1, const arbor::Cluster *pCluster2, float &centroidDifference);

	 /**
	  * @brief Return the distance of closest approach of the two clusters, i.e, the </br>
	  * minimum distance between their calo hits
	  *
	  * @param pCluster1 the first cluster
	  * @param pCluster2 the second cluster
	  * @param distance the distance of closest approach to receive (by reference)
	  */
	 static pandora::StatusCode GetClosestDistanceApproach(const arbor::Cluster *pCluster1, const arbor::Cluster *pCluster2, float &distance);

	 /**
	  *
	  */
	 static pandora::StatusCode FitPoints(const pandora::CartesianPointList &pointList, pandora::ClusterHelper::ClusterFitResult &clusterFitResult);

	 /**
	  *
	  */
	 static pandora::StatusCode GetReferenceDirection(const Object *pObject,	float backwardConnectorWeight,
	 		float forwardConnectorWeight, pandora::CartesianVector &meanBackwardDirection);

	 /**
	  *
	  */
	 static pandora::StatusCode GetReferenceDirection(const Object *pObject,	float backwardConnectorWeight,
	 		float forwardConnectorWeight, unsigned int depth, unsigned int numberOfForwardLayers, pandora::CartesianVector &meanBackwardDirection);

	 /**
	  *
	  */
	 static pandora::StatusCode GetKappaParameter(const Object *pInnerObject, const Object *pOuterObject, const pandora::CartesianVector &referenceVector,
	 		float thetaPower, float distancePower, float &kappaParameter);

 private:

	 /**
	  *
	  */
	 static pandora::StatusCode RecursiveReferenceDirection(const Object *pObject,
	 		float forwardConnectorWeight, unsigned int &currentDepth, unsigned int maxForwardLayer,
	 		pandora::CartesianVector &meanBackwardDirection);

};

} 

#endif  //  ARBORHELPER_H
