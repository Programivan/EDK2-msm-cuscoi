function platform_pre_build(){
	return 0
}

function platform_build_kernel(){
	local FD_FILE=""
	if [ -f "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/${SOC_PLATFORM}_UEFI.fd" ]; then
		FD_FILE="${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/${SOC_PLATFORM}_UEFI.fd"
	elif [ -f "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/${SOC_PLATFORM_L}_UEFI.fd" ]; then
		FD_FILE="${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/${SOC_PLATFORM_L}_UEFI.fd"
	else
		echo "ERROR: UEFI FD file not found!" >&2
		ls -la "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/" >&2
		return 1
	fi

	cat \
		"${ROOTDIR}/tools/BootShim/BootShim.bin" \
		"${FD_FILE}" \
		> "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/${SOC_PLATFORM}_UEFI.fd-bootshim" \
		|| return "$?"
	gzip -c \
		< "${WORKSPACE}/Build/${DEVICE}/${_MODE}_${TOOLCHAIN}/FV/${SOC_PLATFORM}_UEFI.fd-bootshim" \
		> "${WORKSPACE}/uefi-${DEVICE}.img.gz" \
		|| return "$?"
	cat \
		"${WORKSPACE}/uefi-${DEVICE}.img.gz" \
		"${ROOTDIR}/Platform/${VENDOR_NAME}/${SOC_PLATFORM_L}/FdtBlob_compat/${PLATFORM_NAME}.dtb" \
		> "${WORKSPACE}/uefi-${DEVICE}.img.gz-dtb" \
		|| return "$?"
	cp "${WORKSPACE}/uefi-${DEVICE}.img.gz-dtb" "${WORKSPACE}/uefi-${DEVICE}-kernel"
}
