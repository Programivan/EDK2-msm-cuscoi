[Defines]
  VENDOR_NAME                    = Motorola
  PLATFORM_NAME                  = cuscoi
  PLATFORM_GUID                  = 74350001-193a-47e3-a7b9-5a435eaab2ee
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010019
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Platform/Qualcomm/sm7435/sm7435.fdf
  DEVICE_DXE_FV_COMPONENTS       = Platform/Motorola/sm7435/cuscoi.fdf.inc

!include Platform/Qualcomm/sm7435/sm7435.dsc

[BuildOptions.common]
  GCC:*_*_AARCH64_CC_FLAGS = -DENABLE_SIMPLE_INIT -DENABLE_LINUX_SIMPLE_MASS_STORAGE

[PcdsFixedAtBuild.common]
  gQcomTokenSpaceGuid.PcdMipiFrameBufferAddress|0xB8000000
  gQcomTokenSpaceGuid.PcdMipiFrameBufferWidth|1080
  gQcomTokenSpaceGuid.PcdMipiFrameBufferHeight|2400
  gQcomTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|32

  # Simple Init
  gSimpleInitTokenSpaceGuid.PcdGuiDefaultDPI|395

  gRenegadePkgTokenSpaceGuid.PcdDeviceVendor|"Motorola"
  gRenegadePkgTokenSpaceGuid.PcdDeviceProduct|"Edge 50 Fusion"
  gRenegadePkgTokenSpaceGuid.PcdDeviceCodeName|"cuscoi"
