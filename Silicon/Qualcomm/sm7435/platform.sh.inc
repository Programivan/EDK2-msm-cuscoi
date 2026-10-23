function platform_pre_build(){
	return 0
}

function platform_build_bootimg_hook(){
	if [ -f "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/sm7435_UEFI.fd" ] && [ ! -f "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/SM7435_UEFI.fd" ]; then
		cp "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/sm7435_UEFI.fd" "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/SM7435_UEFI.fd"
	fi
	if [ -f "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/SM7435_UEFI.fd" ] && [ ! -f "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/sm7435_UEFI.fd" ]; then
		cp "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/SM7435_UEFI.fd" "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/sm7435_UEFI.fd"
	fi
	return 0
}
