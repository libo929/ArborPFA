########################################################
# cmake file for building ArobrPFA
# @author Jan Engels, John Marshall, Remi Ete
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.2 FATAL_ERROR)
########################################################


# project name
PROJECT( ArborPFA )


### PACKAGE VERSIONS ########################################################
SET( ${PROJECT_NAME}_VERSION_MAJOR 2 )
SET( ${PROJECT_NAME}_VERSION_MINOR 5 )
SET( ${PROJECT_NAME}_VERSION_PATCH 2 )

# versions of ArborPFA subpackages
SET( ArborContent_version         "newDev" )
SET( MarlinArbor_version          "newDev" )

### DEPENDENCIES ############################################################
INCLUDE( ExternalProject )

FOREACH( _path ${CMAKE_PREFIX_PATH} )                                                                                    
   FIND_PATH(pandora_cmake_path "PandoraCMakeSettings.cmake" ${_path}/cmakemodules)
   IF (pandora_cmake_path)
      BREAK()
   ENDIF()
ENDFOREACH() 

IF (pandora_cmake_path)
   LIST(APPEND CMAKE_MODULE_PATH ${pandora_cmake_path})
ENDIF()
INCLUDE(PandoraCMakeSettings)

OPTION( INSTALL_DOC "Set to OFF to skip build/install Documentation" OFF )
MESSAGE( STATUS "INSTALL_DOC: ${INSTALL_DOC}" )

OPTION( MARLIN_ARBOR "Build MarlinArbor library (lcio and marlin)" ON )
MESSAGE( STATUS "MARLIN_ARBOR: ${MARLIN_ARBOR}" )

OPTION( USE_ARBOR_MASTER "Whether to use the ArborContent and MarlinArbor master branches" OFF )
MESSAGE( STATUS "USE_ARBOR_MASTER: ${USE_ARBOR_MASTER}" )

IF( USE_ARBOR_MASTER )
	SET( ArborContent_version         "master" )
	SET( MarlinArbor_version          "master" )
ENDIF()

# ----- download settings ----------------------------------------------------
SET( ArborContent_repository        "https://github.com/libo929/ArborContent.git" )
SET( MarlinArbor_repository         "https://github.com/libo929/MarlinArbor.git" )
# ----------------------------------------------------------------------------

# In order to pass semicolon-separated lists over the command line to all packages,
# we need to separate list elements with '%' instead of the standard cmake list separator ';'
# The list separator needs also to be redefined in the ExternalProject_Add calls by setting
# the variable LIST_SEPARATOR

FOREACH( _path ${CMAKE_PREFIX_PATH} )
    SET( CMAKE_PREFIX_PATH_FIXED ${CMAKE_PREFIX_PATH_FIXED}%${_path} )
ENDFOREACH()

FOREACH( _path ${CMAKE_MODULE_PATH} )
    SET( CMAKE_MODULE_PATH_FIXED ${CMAKE_MODULE_PATH_FIXED}%${_path} )
ENDFOREACH()



# ----- cmake arguments common to ALL cmake packages -------------------------
SET( common_cmake_args
     "-DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH_FIXED}"
     "-DCMAKE_MODULE_PATH=${CMAKE_MODULE_PATH_FIXED}"
     "-DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}"
     "-DINSTALL_DOC=${INSTALL_DOC}"
     "-DUSE_CXX11=${USE_CXX11}"
)
# ----------------------------------------------------------------------------

IF( PANDORA_MONITORING )
    ExternalProject_Add( ArborContent
        GIT_REPOSITORY ${ArborContent_repository}
        GIT_TAG ${ArborContent_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=ON"
        LIST_SEPARATOR %
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ArborPFA
    )
    
ELSE()
    ExternalProject_Add( ArborContent
        GIT_REPOSITORY ${ArborContent_repository}
        GIT_TAG ${ArborContent_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=OFF"
        LIST_SEPARATOR %
		SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ArborPFA
    )
    
    IF( MARLIN_ARBOR )
        ExternalProject_Add( MarlinArbor
        DEPENDS ArborContent
        GIT_REPOSITORY ${MarlinArbor_repository}
        GIT_TAG ${MarlinArbor_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=OFF"
        LIST_SEPARATOR %
		SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MarlinArbor
    )
    ENDIF()
ENDIF()


# display some variables and write them to cache
PANDORA_DISPLAY_STD_VARIABLES()

INSTALL( FILES "ChangeLog.txt" DESTINATION "docs" OPTIONAL )
