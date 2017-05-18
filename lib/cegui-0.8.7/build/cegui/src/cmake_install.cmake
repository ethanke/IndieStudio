# Install script for directory: /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/build/lib/libCEGUIBase-0.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCEGUIBase-0.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCEGUIBase-0.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCEGUIBase-0.dylib")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI" TYPE FILE FILES
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Affector.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Animation.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/AnimationInstance.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/AnimationManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Animation_xmlHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Base.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/BasicImage.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/BasicRenderedStringParser.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/BidiVisualMapping.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/BoundSlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/CEGUI.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/CentredRenderedString.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ChainedXMLHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Clipboard.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Colour.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ColourRect.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/CompositeResourceProvider.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Config_xmlHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/CoordConverter.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/DataContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/DefaultLogger.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/DefaultRenderedStringParser.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/DefaultResourceProvider.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/DynamicModule.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Element.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Event.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/EventArgs.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/EventSet.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Exceptions.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FactoryModule.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FactoryRegisterer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Font.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FontGlyph.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FontManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Font_xmlHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FormattedRenderedString.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ForwardRefs.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FreeFunctionSlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FreeTypeFont.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FribidiVisualMapping.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorCopySlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorPointerSlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorReferenceBinder.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/FunctorReferenceSlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/GUIContext.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/GUILayout_xmlHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/GeometryBuffer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/GlobalEventSet.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/IconvStringTranscoder.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Image.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ImageCodec.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ImageFactory.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ImageManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/InjectedInputReceiver.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/InputEvent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Interpolator.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/IteratorBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/JustifiedRenderedString.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/KeyFrame.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/LeftAlignedRenderedString.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/LinkedEvent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Logger.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MemberFunctionSlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryAllocatedObject.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryAllocation.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryOgreAllocator.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MemorySTLWrapper.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MemoryStdAllocator.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MinibidiVisualMapping.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MinizipResourceProvider.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/MouseCursor.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/NamedElement.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/NamedXMLResourceManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/PCRERegexMatcher.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/PixmapFont.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Property.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/PropertyHelper.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/PropertySet.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Quaternion.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Rect.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RefCounted.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RegexMatcher.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderEffect.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderEffectFactory.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderEffectManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderQueue.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderTarget.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedString.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringImageComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringParser.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringTextComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringWidgetComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderedStringWordWrapper.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Renderer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderingContext.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderingSurface.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RenderingWindow.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ResourceProvider.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/RightAlignedRenderedString.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Scheme.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/SchemeManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Scheme_xmlHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/ScriptModule.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/SimpleTimer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Singleton.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Size.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/SlotFunctorBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/String.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/StringTranscoder.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/SubscriberSlot.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/System.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/SystemKeys.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TextUtils.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Texture.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TextureTarget.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplInterpolators.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplProperty.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplWRFactoryRegisterer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowFactory.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowFactoryRegisterer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowProperty.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowRendererFactory.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TplWindowRendererProperty.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/TypedProperty.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/UDim.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Vector.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Vertex.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Win32StringTranscoder.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/Window.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/WindowFactory.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/WindowFactoryManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/WindowManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/WindowRenderer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/WindowRendererManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/XMLAttributes.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/XMLHandler.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/XMLParser.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/XMLSerializer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/build/cegui/src/../include/CEGUI/Config.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/build/cegui/src/../include/CEGUI/ModuleConfig.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/build/cegui/src/../include/CEGUI/Version.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/widgets" TYPE FILE FILES
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/All.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ButtonBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ClippedContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ComboDropList.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Combobox.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/DefaultWindow.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/DragContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Editbox.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/FrameWindow.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/GridLayoutContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/GroupBox.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/HorizontalLayoutContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ItemEntry.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ItemListBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ItemListbox.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/LayoutCell.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/LayoutContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListHeader.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListHeaderSegment.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Listbox.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListboxItem.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ListboxTextItem.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MenuBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MenuItem.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Menubar.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MultiColumnList.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/MultiLineEditbox.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/PopupMenu.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ProgressBar.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/PushButton.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/RadioButton.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ScrollablePane.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Scrollbar.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ScrolledContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ScrolledItemListBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/SequentialLayoutContainer.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Slider.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Spinner.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/TabButton.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/TabControl.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Thumb.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Titlebar.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/ToggleButton.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Tooltip.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/Tree.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/TreeItem.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/widgets/VerticalLayoutContainer.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/falagard" TYPE FILE FILES
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/ComponentBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/Dimensions.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/Enums.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/EventAction.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/EventLinkDefinition.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/FalagardPropertyBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/FormattingSetting.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/FrameComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/ImageryComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/ImagerySection.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/LayerSpecification.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/NamedArea.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/NamedDefinitionCollator.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyDefinition.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyDefinitionBase.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyInitialiser.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/PropertyLinkDefinition.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/SectionSpecification.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/StateImagery.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/TextComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/WidgetComponent.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/WidgetLookFeel.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/WidgetLookManager.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/XMLEnumHelper.h"
    "/Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/lib/cegui-0.8.7/cegui/src/../include/CEGUI/falagard/XMLHandler.h"
    )
endif()

