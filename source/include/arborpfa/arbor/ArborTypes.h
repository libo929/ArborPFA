/*
 *
 * ArborTypes.h header template automatically generated by a class generator
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


#ifndef ARBORTYPES_H
#define ARBORTYPES_H

#include <set>
#include <utility>
#include <vector>

namespace arborpfa
{

	class Connector;
	class ArborObject;

	typedef std::set<Connector*>         ConnectorList;
	typedef std::vector<Connector*>      ConnectorVector;

	typedef std::set<ArborObject*>       ArborObjectList;
	typedef std::vector<ArborObject*>    ArborObjectVector;

	typedef std::pair<ArborObject*,ArborObject*> ArborObjectPair;

	/**
	 * @brief ConnectorDirection enum
	 */
	enum ConnectorDirection
	{
		BACKWARD,
		FORWARD
	};

	/**
	 * @brief ArborObjectType enum
	 */
	enum ArborObjectType
	{
		CALO_HIT,
		CLUSTER,
		TRACK,
		UNDEFINED_OBJECT
	};

	/**
	 * @brief ConnectorType enum
	 */
	enum ConnectorType
	{
		INITIAL_CONNECTOR,
		FIRST_CLEANING,
		SECOND_CLEANING,
		FINAL_DECISION,
		UNDEFINED_CONNECTOR
	};

} 

#endif  //  ARBORTYPES_H
