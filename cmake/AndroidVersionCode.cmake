function(pad_version_string STRING OUTPUT)
	string(LENGTH "${STRING}" STRING_LENGTH)
	math(EXPR REPEAT_COUNT "2 - ${STRING_LENGTH}")
	string(REPEAT "0" ${REPEAT_COUNT} FILL)
	set(${OUTPUT} "${FILL}${STRING}" PARENT_SCOPE)
endfunction()

function(android_version_code OUTPUT)
	pad_version_string("${PROJECT_VERSION_MAJOR}" VERSION_MAJOR_CODE)
	pad_version_string("${PROJECT_VERSION_MINOR}" VERSION_MINOR_CODE)
	pad_version_string("${PROJECT_VERSION_PATCH}" VERSION_PATCH_CODE)
	string(CONCAT VERSION_CODE
		${VERSION_MAJOR_CODE}
		${VERSION_MINOR_CODE}
		${VERSION_PATCH_CODE}
	)
	set(${OUTPUT} ${VERSION_CODE} PARENT_SCOPE)
endfunction()