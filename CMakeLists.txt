########################################################
# cmake file for building ArobrPFA
# @author Jan Engels, John Marshall, Remi Ete
CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
########################################################


# project name
PROJECT( ArborPFA )


### PACKAGE VERSIONS ########################################################
SET( ${PROJECT_NAME}_VERSION_MAJOR 2 )
SET( ${PROJECT_NAME}_VERSION_MINOR 5 )
SET( ${PROJECT_NAME}_VERSION_PATCH 2 )

# versions of ArborPFA subpackages
# don't forget to update when releasing ArborPFA
# e.g. SET( PandoraSDK_version "v01-00-00" )
SET( PandoraSDK_version           "v02-03-00" )
SET( PandoraMonitoring_version    "v02-03-00" )
SET( ArborContent_version         "v01-05-01" )
SET( MarlinArbor_version          "v01-04-02" )

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmakemodules)

### DEPENDENCIES ############################################################
INCLUDE( ExternalProject )
INCLUDE( PandoraCMakeSettings )

OPTION( PANDORA_MONITORING "Build PandoraMonitoring library (requires ROOT)" OFF )
MESSAGE( STATUS "PANDORA_MONITORING: ${PANDORA_MONITORING}" )

OPTION( INSTALL_DOC "Set to OFF to skip build/install Documentation" OFF )
MESSAGE( STATUS "INSTALL_DOC: ${INSTALL_DOC}" )

OPTION( MARLIN_ARBOR "Build MarlinArbor library (lcio and marlin)" OFF )
MESSAGE( STATUS "MARLIN_ARBOR: ${MARLIN_ARBOR}" )

OPTION( USE_CXX11 "Whether to use cpp 11 features" OFF )
MESSAGE( STATUS "USE_CXX11: ${USE_CXX11}" )

OPTION( USE_PANDORA_MASTER "Whether to use the PandoraSDK and PandoraMonitoring master branches" OFF )
MESSAGE( STATUS "USE_PANDORA_MASTER: ${USE_PANDORA_MASTER}" )

OPTION( USE_ARBOR_MASTER "Whether to use the ArborContent and MarlinArbor master branches" OFF )
MESSAGE( STATUS "USE_ARBOR_MASTER: ${USE_ARBOR_MASTER}" )

IF( USE_PANDORA_MASTER )
	SET( PandoraSDK_version           "master" )
	SET( PandoraMonitoring_version    "master" )
ENDIF()

IF( USE_ARBOR_MASTER )
	SET( ArborContent_version         "master" )
	SET( MarlinArbor_version          "master" )
ENDIF()

# ----- download settings ----------------------------------------------------
SET( PandoraSDK_repository          "https://github.com/PandoraPFA/PandoraSDK.git" )
SET( PandoraMonitoring_repository   "https://github.com/PandoraPFA/PandoraMonitoring.git" )
SET( ArborContent_repository        "https://github.com/ArborPFA/ArborContent.git" )
SET( MarlinArbor_repository         "https://github.com/ArborPFA/MarlinArbor.git" )
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

ExternalProject_Add( PandoraSDK
    GIT_REPOSITORY ${PandoraSDK_repository}
    GIT_TAG ${PandoraSDK_version}
    CMAKE_ARGS ${common_cmake_args} "-DPandoraSDK_BUILD_DOCS=${INSTALL_DOC}"
    LIST_SEPARATOR %
)

IF( PANDORA_MONITORING )
    ExternalProject_Add( PandoraMonitoring
        DEPENDS PandoraSDK
        GIT_REPOSITORY ${PandoraMonitoring_repository}
        GIT_TAG ${PandoraMonitoring_version}
        CMAKE_ARGS ${common_cmake_args} "-DPandoraMonitoring_BUILD_DOCS=${INSTALL_DOC}"
        LIST_SEPARATOR %
    )

    ExternalProject_Add( ArborContent
        DEPENDS PandoraSDK PandoraMonitoring
        GIT_REPOSITORY ${ArborContent_repository}
        GIT_TAG ${ArborContent_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=ON"
        LIST_SEPARATOR %
    )
    
    IF( MARLIN_ARBOR )
        ExternalProject_Add( MarlinArbor
        DEPENDS PandoraSDK PandoraMonitoring ArborContent
        GIT_REPOSITORY ${MarlinArbor_repository}
        GIT_TAG ${MarlinArbor_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=ON"
        LIST_SEPARATOR %
    )
    ENDIF()
ELSE()
    ExternalProject_Add( ArborContent
        DEPENDS PandoraSDK
        GIT_REPOSITORY ${ArborContent_repository}
        GIT_TAG ${ArborContent_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=OFF"
        LIST_SEPARATOR %
    )
    
    IF( MARLIN_ARBOR )
        ExternalProject_Add( MarlinArbor
        DEPENDS PandoraSDK ArborContent
        GIT_REPOSITORY ${MarlinArbor_repository}
        GIT_TAG ${MarlinArbor_version}
        CMAKE_ARGS ${common_cmake_args} "-DPANDORA_MONITORING=OFF"
        LIST_SEPARATOR %
    )
    ENDIF()
ENDIF()



# display some variables and write them to cache
PANDORA_DISPLAY_STD_VARIABLES()
