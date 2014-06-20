  /// \file SDHCALEnergyResolutionFunction.cc
/*
 *
 * SDHCALEnergyResolutionFunction.cc source template automatically generated by a class generator
 * Creation date : jeu. juin 19 2014
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


#include "arborpfa/content/SDHCALEnergyResolutionFunction.h"

namespace arbor
{

pandora::StatusCode SDHCALEnergyResolutionFunction::GetEnergyResolution(float energy, float &energyResolution) const
{
	energyResolution = std::sqrt(m_energyFactor*m_energyFactor/energy + m_constantFactor*m_constantFactor + m_energySquareFactor*m_energySquareFactor/(energy*energy));
	return pandora::STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------

pandora::StatusCode SDHCALEnergyResolutionFunction::ReadSettings(const pandora::TiXmlHandle xmlHandle)
{
 PANDORA_THROW_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
     "EnergyFactor", m_energyFactor));

 PANDORA_THROW_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
     "ConstantFactor", m_constantFactor));

 PANDORA_THROW_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
     "EnergySquareFactor", m_energySquareFactor));

	return pandora::STATUS_CODE_SUCCESS;
}


} 

