/*
 *
 * ArborApi.h header template automatically generated by a class generator
 * Creation date : lun. f�vr. 10 2014
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


#ifndef ARBORAPI_H
#define ARBORAPI_H

// pandora
#include "Pandora/PandoraInternal.h"
#include "Pandora/PandoraInputTypes.h"

#include "arborpfa/arbor/ArborTypes.h"


namespace pandora
{
	class Pandora;
}


namespace arborpfa {

class Arbor;
class ArborAlgorithmFactory;

/** 
 * @brief ArborApi class
 */ 
class ArborApi
{

 public:

		/**
		 *
		 */
		static pandora::StatusCode PrepareEvent(const Arbor &arbor);

		/**
			* @brief Get the current connector list
			*
			* @param pConnectorList the connector to receive
			* @param listName the connector list name
			*/
	 static pandora::StatusCode GetCurrentConnectorList(const Arbor &arbor, const ConnectorList *&pConnectorList);

	 /**
	  *
	  */
	 static pandora::StatusCode GetConnectorList(const Arbor &arbor, const std::string &listName, const ConnectorList *&pConnectorList);

		/**
			* @brief Register the reset function of Arbor framework
			*/
		static pandora::StatusCode RegisterResetFunction();

		/**
		 * @brief Reset the event before next event
		 */
		static pandora::StatusCode Reset(const Arbor &arbor);

		/**
		 *
		 */
		static pandora::StatusCode RegisterAlgorithmFactory(const pandora::Pandora &pPandora, Arbor &pArbor, const std::string &factoryName, ArborAlgorithmFactory *pFactory);

		// TODO Think about a a function like SetConnectorRelation(void *, ..., ...) to link LCRelation with LCObject


}; 

} 

#endif  //  ARBORAPI_H