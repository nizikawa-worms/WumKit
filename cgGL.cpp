#include "hook_macro.h"
#include <filesystem>
#include <iostream>
#include <windows.h>

HINSTANCE mHinst = 0, mHinstDLL = 0;

UINT_PTR mProcs[86] = {0};

LPCSTR mImportNames[] = {
	"cgGLBindProgram",
	"cgGLCreateBuffer",
	"cgGLDisableClientState",
	"cgGLDisableProfile",
	"cgGLDisableProgramProfiles",
	"cgGLDisableTextureParameter",
	"cgGLEnableClientState",
	"cgGLEnableProfile",
	"cgGLEnableProgramProfiles",
	"cgGLEnableTextureParameter",
	"cgGLGetBufferObject",
	"cgGLGetLatestProfile",
	"cgGLGetManageTextureParameters",
	"cgGLGetMatrixParameterArraydc",
	"cgGLGetMatrixParameterArraydr",
	"cgGLGetMatrixParameterArrayfc",
	"cgGLGetMatrixParameterArrayfr",
	"cgGLGetMatrixParameterdc",
	"cgGLGetMatrixParameterdr",
	"cgGLGetMatrixParameterfc",
	"cgGLGetMatrixParameterfr",
	"cgGLGetOptimalOptions",
	"cgGLGetParameter1d",
	"cgGLGetParameter1f",
	"cgGLGetParameter2d",
	"cgGLGetParameter2f",
	"cgGLGetParameter3d",
	"cgGLGetParameter3f",
	"cgGLGetParameter4d",
	"cgGLGetParameter4f",
	"cgGLGetParameterArray1d",
	"cgGLGetParameterArray1f",
	"cgGLGetParameterArray2d",
	"cgGLGetParameterArray2f",
	"cgGLGetParameterArray3d",
	"cgGLGetParameterArray3f",
	"cgGLGetParameterArray4d",
	"cgGLGetParameterArray4f",
	"cgGLGetProgramID",
	"cgGLGetTextureEnum",
	"cgGLGetTextureParameter",
	"cgGLIsProfileSupported",
	"cgGLIsProgramLoaded",
	"cgGLLoadProgram",
	"cgGLRegisterStates",
	"cgGLSetDebugMode",
	"cgGLSetManageTextureParameters",
	"cgGLSetMatrixParameterArraydc",
	"cgGLSetMatrixParameterArraydr",
	"cgGLSetMatrixParameterArrayfc",
	"cgGLSetMatrixParameterArrayfr",
	"cgGLSetMatrixParameterdc",
	"cgGLSetMatrixParameterdr",
	"cgGLSetMatrixParameterfc",
	"cgGLSetMatrixParameterfr",
	"cgGLSetOptimalOptions",
	"cgGLSetParameter1d",
	"cgGLSetParameter1dv",
	"cgGLSetParameter1f",
	"cgGLSetParameter1fv",
	"cgGLSetParameter2d",
	"cgGLSetParameter2dv",
	"cgGLSetParameter2f",
	"cgGLSetParameter2fv",
	"cgGLSetParameter3d",
	"cgGLSetParameter3dv",
	"cgGLSetParameter3f",
	"cgGLSetParameter3fv",
	"cgGLSetParameter4d",
	"cgGLSetParameter4dv",
	"cgGLSetParameter4f",
	"cgGLSetParameter4fv",
	"cgGLSetParameterArray1d",
	"cgGLSetParameterArray1f",
	"cgGLSetParameterArray2d",
	"cgGLSetParameterArray2f",
	"cgGLSetParameterArray3d",
	"cgGLSetParameterArray3f",
	"cgGLSetParameterArray4d",
	"cgGLSetParameterArray4f",
	"cgGLSetParameterPointer",
	"cgGLSetStateMatrixParameter",
	"cgGLSetTextureParameter",
	"cgGLSetupSampler",
	"cgGLUnbindProgram",
	"cgGLUnloadProgram",
};

#ifndef _DEBUG
inline void log_info(const char *info) {
}
#else
FILE *debug;

inline void log_info(const char *info) {
	fprintf(debug, "%s\n", info);
	fflush(debug);
}
#endif

#include "empty.h"

inline void _hook_setup() {
#ifdef CGGLBINDPROGRAM
	cgGLBindProgram_real = (cgGLBindProgram_ptr)mProcs[0];
	mProcs[0] = (UINT_PTR)&cgGLBindProgram_fake;
#endif
#ifdef CGGLCREATEBUFFER
	cgGLCreateBuffer_real = (cgGLCreateBuffer_ptr)mProcs[1];
	mProcs[1] = (UINT_PTR)&cgGLCreateBuffer_fake;
#endif
#ifdef CGGLDISABLECLIENTSTATE
	cgGLDisableClientState_real = (cgGLDisableClientState_ptr)mProcs[2];
	mProcs[2] = (UINT_PTR)&cgGLDisableClientState_fake;
#endif
#ifdef CGGLDISABLEPROFILE
	cgGLDisableProfile_real = (cgGLDisableProfile_ptr)mProcs[3];
	mProcs[3] = (UINT_PTR)&cgGLDisableProfile_fake;
#endif
#ifdef CGGLDISABLEPROGRAMPROFILES
	cgGLDisableProgramProfiles_real = (cgGLDisableProgramProfiles_ptr)mProcs[4];
	mProcs[4] = (UINT_PTR)&cgGLDisableProgramProfiles_fake;
#endif
#ifdef CGGLDISABLETEXTUREPARAMETER
	cgGLDisableTextureParameter_real = (cgGLDisableTextureParameter_ptr)mProcs[5];
	mProcs[5] = (UINT_PTR)&cgGLDisableTextureParameter_fake;
#endif
#ifdef CGGLENABLECLIENTSTATE
	cgGLEnableClientState_real = (cgGLEnableClientState_ptr)mProcs[6];
	mProcs[6] = (UINT_PTR)&cgGLEnableClientState_fake;
#endif
#ifdef CGGLENABLEPROFILE
	cgGLEnableProfile_real = (cgGLEnableProfile_ptr)mProcs[7];
	mProcs[7] = (UINT_PTR)&cgGLEnableProfile_fake;
#endif
#ifdef CGGLENABLEPROGRAMPROFILES
	cgGLEnableProgramProfiles_real = (cgGLEnableProgramProfiles_ptr)mProcs[8];
	mProcs[8] = (UINT_PTR)&cgGLEnableProgramProfiles_fake;
#endif
#ifdef CGGLENABLETEXTUREPARAMETER
	cgGLEnableTextureParameter_real = (cgGLEnableTextureParameter_ptr)mProcs[9];
	mProcs[9] = (UINT_PTR)&cgGLEnableTextureParameter_fake;
#endif
#ifdef CGGLGETBUFFEROBJECT
	cgGLGetBufferObject_real = (cgGLGetBufferObject_ptr)mProcs[10];
	mProcs[10] = (UINT_PTR)&cgGLGetBufferObject_fake;
#endif
#ifdef CGGLGETLATESTPROFILE
	cgGLGetLatestProfile_real = (cgGLGetLatestProfile_ptr)mProcs[11];
	mProcs[11] = (UINT_PTR)&cgGLGetLatestProfile_fake;
#endif
#ifdef CGGLGETMANAGETEXTUREPARAMETERS
	cgGLGetManageTextureParameters_real = (cgGLGetManageTextureParameters_ptr)mProcs[12];
	mProcs[12] = (UINT_PTR)&cgGLGetManageTextureParameters_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERARRAYDC
	cgGLGetMatrixParameterArraydc_real = (cgGLGetMatrixParameterArraydc_ptr)mProcs[13];
	mProcs[13] = (UINT_PTR)&cgGLGetMatrixParameterArraydc_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERARRAYDR
	cgGLGetMatrixParameterArraydr_real = (cgGLGetMatrixParameterArraydr_ptr)mProcs[14];
	mProcs[14] = (UINT_PTR)&cgGLGetMatrixParameterArraydr_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERARRAYFC
	cgGLGetMatrixParameterArrayfc_real = (cgGLGetMatrixParameterArrayfc_ptr)mProcs[15];
	mProcs[15] = (UINT_PTR)&cgGLGetMatrixParameterArrayfc_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERARRAYFR
	cgGLGetMatrixParameterArrayfr_real = (cgGLGetMatrixParameterArrayfr_ptr)mProcs[16];
	mProcs[16] = (UINT_PTR)&cgGLGetMatrixParameterArrayfr_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERDC
	cgGLGetMatrixParameterdc_real = (cgGLGetMatrixParameterdc_ptr)mProcs[17];
	mProcs[17] = (UINT_PTR)&cgGLGetMatrixParameterdc_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERDR
	cgGLGetMatrixParameterdr_real = (cgGLGetMatrixParameterdr_ptr)mProcs[18];
	mProcs[18] = (UINT_PTR)&cgGLGetMatrixParameterdr_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERFC
	cgGLGetMatrixParameterfc_real = (cgGLGetMatrixParameterfc_ptr)mProcs[19];
	mProcs[19] = (UINT_PTR)&cgGLGetMatrixParameterfc_fake;
#endif
#ifdef CGGLGETMATRIXPARAMETERFR
	cgGLGetMatrixParameterfr_real = (cgGLGetMatrixParameterfr_ptr)mProcs[20];
	mProcs[20] = (UINT_PTR)&cgGLGetMatrixParameterfr_fake;
#endif
#ifdef CGGLGETOPTIMALOPTIONS
	cgGLGetOptimalOptions_real = (cgGLGetOptimalOptions_ptr)mProcs[21];
	mProcs[21] = (UINT_PTR)&cgGLGetOptimalOptions_fake;
#endif
#ifdef CGGLGETPARAMETER1D
	cgGLGetParameter1d_real = (cgGLGetParameter1d_ptr)mProcs[22];
	mProcs[22] = (UINT_PTR)&cgGLGetParameter1d_fake;
#endif
#ifdef CGGLGETPARAMETER1F
	cgGLGetParameter1f_real = (cgGLGetParameter1f_ptr)mProcs[23];
	mProcs[23] = (UINT_PTR)&cgGLGetParameter1f_fake;
#endif
#ifdef CGGLGETPARAMETER2D
	cgGLGetParameter2d_real = (cgGLGetParameter2d_ptr)mProcs[24];
	mProcs[24] = (UINT_PTR)&cgGLGetParameter2d_fake;
#endif
#ifdef CGGLGETPARAMETER2F
	cgGLGetParameter2f_real = (cgGLGetParameter2f_ptr)mProcs[25];
	mProcs[25] = (UINT_PTR)&cgGLGetParameter2f_fake;
#endif
#ifdef CGGLGETPARAMETER3D
	cgGLGetParameter3d_real = (cgGLGetParameter3d_ptr)mProcs[26];
	mProcs[26] = (UINT_PTR)&cgGLGetParameter3d_fake;
#endif
#ifdef CGGLGETPARAMETER3F
	cgGLGetParameter3f_real = (cgGLGetParameter3f_ptr)mProcs[27];
	mProcs[27] = (UINT_PTR)&cgGLGetParameter3f_fake;
#endif
#ifdef CGGLGETPARAMETER4D
	cgGLGetParameter4d_real = (cgGLGetParameter4d_ptr)mProcs[28];
	mProcs[28] = (UINT_PTR)&cgGLGetParameter4d_fake;
#endif
#ifdef CGGLGETPARAMETER4F
	cgGLGetParameter4f_real = (cgGLGetParameter4f_ptr)mProcs[29];
	mProcs[29] = (UINT_PTR)&cgGLGetParameter4f_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY1D
	cgGLGetParameterArray1d_real = (cgGLGetParameterArray1d_ptr)mProcs[30];
	mProcs[30] = (UINT_PTR)&cgGLGetParameterArray1d_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY1F
	cgGLGetParameterArray1f_real = (cgGLGetParameterArray1f_ptr)mProcs[31];
	mProcs[31] = (UINT_PTR)&cgGLGetParameterArray1f_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY2D
	cgGLGetParameterArray2d_real = (cgGLGetParameterArray2d_ptr)mProcs[32];
	mProcs[32] = (UINT_PTR)&cgGLGetParameterArray2d_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY2F
	cgGLGetParameterArray2f_real = (cgGLGetParameterArray2f_ptr)mProcs[33];
	mProcs[33] = (UINT_PTR)&cgGLGetParameterArray2f_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY3D
	cgGLGetParameterArray3d_real = (cgGLGetParameterArray3d_ptr)mProcs[34];
	mProcs[34] = (UINT_PTR)&cgGLGetParameterArray3d_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY3F
	cgGLGetParameterArray3f_real = (cgGLGetParameterArray3f_ptr)mProcs[35];
	mProcs[35] = (UINT_PTR)&cgGLGetParameterArray3f_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY4D
	cgGLGetParameterArray4d_real = (cgGLGetParameterArray4d_ptr)mProcs[36];
	mProcs[36] = (UINT_PTR)&cgGLGetParameterArray4d_fake;
#endif
#ifdef CGGLGETPARAMETERARRAY4F
	cgGLGetParameterArray4f_real = (cgGLGetParameterArray4f_ptr)mProcs[37];
	mProcs[37] = (UINT_PTR)&cgGLGetParameterArray4f_fake;
#endif
#ifdef CGGLGETPROGRAMID
	cgGLGetProgramID_real = (cgGLGetProgramID_ptr)mProcs[38];
	mProcs[38] = (UINT_PTR)&cgGLGetProgramID_fake;
#endif
#ifdef CGGLGETTEXTUREENUM
	cgGLGetTextureEnum_real = (cgGLGetTextureEnum_ptr)mProcs[39];
	mProcs[39] = (UINT_PTR)&cgGLGetTextureEnum_fake;
#endif
#ifdef CGGLGETTEXTUREPARAMETER
	cgGLGetTextureParameter_real = (cgGLGetTextureParameter_ptr)mProcs[40];
	mProcs[40] = (UINT_PTR)&cgGLGetTextureParameter_fake;
#endif
#ifdef CGGLISPROFILESUPPORTED
	cgGLIsProfileSupported_real = (cgGLIsProfileSupported_ptr)mProcs[41];
	mProcs[41] = (UINT_PTR)&cgGLIsProfileSupported_fake;
#endif
#ifdef CGGLISPROGRAMLOADED
	cgGLIsProgramLoaded_real = (cgGLIsProgramLoaded_ptr)mProcs[42];
	mProcs[42] = (UINT_PTR)&cgGLIsProgramLoaded_fake;
#endif
#ifdef CGGLLOADPROGRAM
	cgGLLoadProgram_real = (cgGLLoadProgram_ptr)mProcs[43];
	mProcs[43] = (UINT_PTR)&cgGLLoadProgram_fake;
#endif
#ifdef CGGLREGISTERSTATES
	cgGLRegisterStates_real = (cgGLRegisterStates_ptr)mProcs[44];
	mProcs[44] = (UINT_PTR)&cgGLRegisterStates_fake;
#endif
#ifdef CGGLSETDEBUGMODE
	cgGLSetDebugMode_real = (cgGLSetDebugMode_ptr)mProcs[45];
	mProcs[45] = (UINT_PTR)&cgGLSetDebugMode_fake;
#endif
#ifdef CGGLSETMANAGETEXTUREPARAMETERS
	cgGLSetManageTextureParameters_real = (cgGLSetManageTextureParameters_ptr)mProcs[46];
	mProcs[46] = (UINT_PTR)&cgGLSetManageTextureParameters_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERARRAYDC
	cgGLSetMatrixParameterArraydc_real = (cgGLSetMatrixParameterArraydc_ptr)mProcs[47];
	mProcs[47] = (UINT_PTR)&cgGLSetMatrixParameterArraydc_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERARRAYDR
	cgGLSetMatrixParameterArraydr_real = (cgGLSetMatrixParameterArraydr_ptr)mProcs[48];
	mProcs[48] = (UINT_PTR)&cgGLSetMatrixParameterArraydr_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERARRAYFC
	cgGLSetMatrixParameterArrayfc_real = (cgGLSetMatrixParameterArrayfc_ptr)mProcs[49];
	mProcs[49] = (UINT_PTR)&cgGLSetMatrixParameterArrayfc_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERARRAYFR
	cgGLSetMatrixParameterArrayfr_real = (cgGLSetMatrixParameterArrayfr_ptr)mProcs[50];
	mProcs[50] = (UINT_PTR)&cgGLSetMatrixParameterArrayfr_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERDC
	cgGLSetMatrixParameterdc_real = (cgGLSetMatrixParameterdc_ptr)mProcs[51];
	mProcs[51] = (UINT_PTR)&cgGLSetMatrixParameterdc_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERDR
	cgGLSetMatrixParameterdr_real = (cgGLSetMatrixParameterdr_ptr)mProcs[52];
	mProcs[52] = (UINT_PTR)&cgGLSetMatrixParameterdr_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERFC
	cgGLSetMatrixParameterfc_real = (cgGLSetMatrixParameterfc_ptr)mProcs[53];
	mProcs[53] = (UINT_PTR)&cgGLSetMatrixParameterfc_fake;
#endif
#ifdef CGGLSETMATRIXPARAMETERFR
	cgGLSetMatrixParameterfr_real = (cgGLSetMatrixParameterfr_ptr)mProcs[54];
	mProcs[54] = (UINT_PTR)&cgGLSetMatrixParameterfr_fake;
#endif
#ifdef CGGLSETOPTIMALOPTIONS
	cgGLSetOptimalOptions_real = (cgGLSetOptimalOptions_ptr)mProcs[55];
	mProcs[55] = (UINT_PTR)&cgGLSetOptimalOptions_fake;
#endif
#ifdef CGGLSETPARAMETER1D
	cgGLSetParameter1d_real = (cgGLSetParameter1d_ptr)mProcs[56];
	mProcs[56] = (UINT_PTR)&cgGLSetParameter1d_fake;
#endif
#ifdef CGGLSETPARAMETER1DV
	cgGLSetParameter1dv_real = (cgGLSetParameter1dv_ptr)mProcs[57];
	mProcs[57] = (UINT_PTR)&cgGLSetParameter1dv_fake;
#endif
#ifdef CGGLSETPARAMETER1F
	cgGLSetParameter1f_real = (cgGLSetParameter1f_ptr)mProcs[58];
	mProcs[58] = (UINT_PTR)&cgGLSetParameter1f_fake;
#endif
#ifdef CGGLSETPARAMETER1FV
	cgGLSetParameter1fv_real = (cgGLSetParameter1fv_ptr)mProcs[59];
	mProcs[59] = (UINT_PTR)&cgGLSetParameter1fv_fake;
#endif
#ifdef CGGLSETPARAMETER2D
	cgGLSetParameter2d_real = (cgGLSetParameter2d_ptr)mProcs[60];
	mProcs[60] = (UINT_PTR)&cgGLSetParameter2d_fake;
#endif
#ifdef CGGLSETPARAMETER2DV
	cgGLSetParameter2dv_real = (cgGLSetParameter2dv_ptr)mProcs[61];
	mProcs[61] = (UINT_PTR)&cgGLSetParameter2dv_fake;
#endif
#ifdef CGGLSETPARAMETER2F
	cgGLSetParameter2f_real = (cgGLSetParameter2f_ptr)mProcs[62];
	mProcs[62] = (UINT_PTR)&cgGLSetParameter2f_fake;
#endif
#ifdef CGGLSETPARAMETER2FV
	cgGLSetParameter2fv_real = (cgGLSetParameter2fv_ptr)mProcs[63];
	mProcs[63] = (UINT_PTR)&cgGLSetParameter2fv_fake;
#endif
#ifdef CGGLSETPARAMETER3D
	cgGLSetParameter3d_real = (cgGLSetParameter3d_ptr)mProcs[64];
	mProcs[64] = (UINT_PTR)&cgGLSetParameter3d_fake;
#endif
#ifdef CGGLSETPARAMETER3DV
	cgGLSetParameter3dv_real = (cgGLSetParameter3dv_ptr)mProcs[65];
	mProcs[65] = (UINT_PTR)&cgGLSetParameter3dv_fake;
#endif
#ifdef CGGLSETPARAMETER3F
	cgGLSetParameter3f_real = (cgGLSetParameter3f_ptr)mProcs[66];
	mProcs[66] = (UINT_PTR)&cgGLSetParameter3f_fake;
#endif
#ifdef CGGLSETPARAMETER3FV
	cgGLSetParameter3fv_real = (cgGLSetParameter3fv_ptr)mProcs[67];
	mProcs[67] = (UINT_PTR)&cgGLSetParameter3fv_fake;
#endif
#ifdef CGGLSETPARAMETER4D
	cgGLSetParameter4d_real = (cgGLSetParameter4d_ptr)mProcs[68];
	mProcs[68] = (UINT_PTR)&cgGLSetParameter4d_fake;
#endif
#ifdef CGGLSETPARAMETER4DV
	cgGLSetParameter4dv_real = (cgGLSetParameter4dv_ptr)mProcs[69];
	mProcs[69] = (UINT_PTR)&cgGLSetParameter4dv_fake;
#endif
#ifdef CGGLSETPARAMETER4F
	cgGLSetParameter4f_real = (cgGLSetParameter4f_ptr)mProcs[70];
	mProcs[70] = (UINT_PTR)&cgGLSetParameter4f_fake;
#endif
#ifdef CGGLSETPARAMETER4FV
	cgGLSetParameter4fv_real = (cgGLSetParameter4fv_ptr)mProcs[71];
	mProcs[71] = (UINT_PTR)&cgGLSetParameter4fv_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY1D
	cgGLSetParameterArray1d_real = (cgGLSetParameterArray1d_ptr)mProcs[72];
	mProcs[72] = (UINT_PTR)&cgGLSetParameterArray1d_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY1F
	cgGLSetParameterArray1f_real = (cgGLSetParameterArray1f_ptr)mProcs[73];
	mProcs[73] = (UINT_PTR)&cgGLSetParameterArray1f_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY2D
	cgGLSetParameterArray2d_real = (cgGLSetParameterArray2d_ptr)mProcs[74];
	mProcs[74] = (UINT_PTR)&cgGLSetParameterArray2d_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY2F
	cgGLSetParameterArray2f_real = (cgGLSetParameterArray2f_ptr)mProcs[75];
	mProcs[75] = (UINT_PTR)&cgGLSetParameterArray2f_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY3D
	cgGLSetParameterArray3d_real = (cgGLSetParameterArray3d_ptr)mProcs[76];
	mProcs[76] = (UINT_PTR)&cgGLSetParameterArray3d_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY3F
	cgGLSetParameterArray3f_real = (cgGLSetParameterArray3f_ptr)mProcs[77];
	mProcs[77] = (UINT_PTR)&cgGLSetParameterArray3f_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY4D
	cgGLSetParameterArray4d_real = (cgGLSetParameterArray4d_ptr)mProcs[78];
	mProcs[78] = (UINT_PTR)&cgGLSetParameterArray4d_fake;
#endif
#ifdef CGGLSETPARAMETERARRAY4F
	cgGLSetParameterArray4f_real = (cgGLSetParameterArray4f_ptr)mProcs[79];
	mProcs[79] = (UINT_PTR)&cgGLSetParameterArray4f_fake;
#endif
#ifdef CGGLSETPARAMETERPOINTER
	cgGLSetParameterPointer_real = (cgGLSetParameterPointer_ptr)mProcs[80];
	mProcs[80] = (UINT_PTR)&cgGLSetParameterPointer_fake;
#endif
#ifdef CGGLSETSTATEMATRIXPARAMETER
	cgGLSetStateMatrixParameter_real = (cgGLSetStateMatrixParameter_ptr)mProcs[81];
	mProcs[81] = (UINT_PTR)&cgGLSetStateMatrixParameter_fake;
#endif
#ifdef CGGLSETTEXTUREPARAMETER
	cgGLSetTextureParameter_real = (cgGLSetTextureParameter_ptr)mProcs[82];
	mProcs[82] = (UINT_PTR)&cgGLSetTextureParameter_fake;
#endif
#ifdef CGGLSETUPSAMPLER
	cgGLSetupSampler_real = (cgGLSetupSampler_ptr)mProcs[83];
	mProcs[83] = (UINT_PTR)&cgGLSetupSampler_fake;
#endif
#ifdef CGGLUNBINDPROGRAM
	cgGLUnbindProgram_real = (cgGLUnbindProgram_ptr)mProcs[84];
	mProcs[84] = (UINT_PTR)&cgGLUnbindProgram_fake;
#endif
#ifdef CGGLUNLOADPROGRAM
	cgGLUnloadProgram_real = (cgGLUnloadProgram_ptr)mProcs[85];
	mProcs[85] = (UINT_PTR)&cgGLUnloadProgram_fake;
#endif
}

void loadDlls() {
	for (const auto &entry : std::filesystem::directory_iterator(".")) {
		if (entry.is_regular_file() && entry.path().extension() == ".dll") {
			const auto filename = entry.path().filename().string();
			if (filename.starts_with("wum")) {
				const auto dllPath = entry.path().string();
				if (auto hModule = LoadLibraryA(dllPath.c_str()); hModule) {
					std::cout << "Loaded: " << dllPath << std::endl;
				} else {
					throw std::runtime_error("Failed to load: " + dllPath + " Error: " + std::to_string(GetLastError()));
				}
			}
		}
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	mHinst = hinstDLL;
	if (fdwReason == DLL_PROCESS_ATTACH) {
		mHinstDLL = LoadLibrary("real_cgGL.dll");
		if (!mHinstDLL) {
			return FALSE;
		}
		for (int i = 0; i < 86; ++i) {
			mProcs[i] = (UINT_PTR)GetProcAddress(mHinstDLL, mImportNames[i]);
		}
		_hook_setup();
#ifdef _DEBUG
		debug = fopen("./debug.log", "a");
#endif

		try {
			loadDlls();
		} catch (const std::filesystem::filesystem_error &e) {
			std::string errorMsg = "Filesystem error: " + std::string(e.what());
			MessageBoxA(nullptr, errorMsg.c_str(), "WUMKit error", MB_ICONERROR | MB_OK);
		} catch (const std::runtime_error &e) {
			std::string errorMsg = "Runtime error: " + std::string(e.what());
			MessageBoxA(nullptr, errorMsg.c_str(), "WUMKit error", MB_ICONERROR | MB_OK);
		} catch (const std::exception &e) {
			std::string errorMsg = "Error: " + std::string(e.what());
			MessageBoxA(nullptr, errorMsg.c_str(), "WUMKit error", MB_ICONERROR | MB_OK);
		} catch (...) {
			std::string errorMsg = "Unknown error occurred";
			MessageBoxA(nullptr, errorMsg.c_str(), "WUMKit error", MB_ICONERROR | MB_OK);
		}

	} else if (fdwReason == DLL_PROCESS_DETACH) {
#ifdef _DEBUG
		fclose(debug);
#endif
		FreeLibrary(mHinstDLL);
	}
	return TRUE;
}

extern "C" __declspec(naked) void __stdcall cgGLBindProgram_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLBindProgram");
#endif
	__asm {jmp mProcs[0 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLCreateBuffer_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLCreateBuffer");
#endif
	__asm {jmp mProcs[1 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLDisableClientState_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLDisableClientState");
#endif
	__asm {jmp mProcs[2 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLDisableProfile_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLDisableProfile");
#endif
	__asm {jmp mProcs[3 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLDisableProgramProfiles_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLDisableProgramProfiles");
#endif
	__asm {jmp mProcs[4 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLDisableTextureParameter_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLDisableTextureParameter");
#endif
	__asm {jmp mProcs[5 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLEnableClientState_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLEnableClientState");
#endif
	__asm {jmp mProcs[6 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLEnableProfile_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLEnableProfile");
#endif
	__asm {jmp mProcs[7 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLEnableProgramProfiles_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLEnableProgramProfiles");
#endif
	__asm {jmp mProcs[8 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLEnableTextureParameter_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLEnableTextureParameter");
#endif
	__asm {jmp mProcs[9 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetBufferObject_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetBufferObject");
#endif
	__asm {jmp mProcs[10 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetLatestProfile_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetLatestProfile");
#endif
	__asm {jmp mProcs[11 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetManageTextureParameters_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetManageTextureParameters");
#endif
	__asm {jmp mProcs[12 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterArraydc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterArraydc");
#endif
	__asm {jmp mProcs[13 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterArraydr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterArraydr");
#endif
	__asm {jmp mProcs[14 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterArrayfc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterArrayfc");
#endif
	__asm {jmp mProcs[15 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterArrayfr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterArrayfr");
#endif
	__asm {jmp mProcs[16 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterdc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterdc");
#endif
	__asm {jmp mProcs[17 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterdr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterdr");
#endif
	__asm {jmp mProcs[18 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterfc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterfc");
#endif
	__asm {jmp mProcs[19 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetMatrixParameterfr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetMatrixParameterfr");
#endif
	__asm {jmp mProcs[20 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetOptimalOptions_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetOptimalOptions");
#endif
	__asm {jmp mProcs[21 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter1d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter1d");
#endif
	__asm {jmp mProcs[22 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter1f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter1f");
#endif
	__asm {jmp mProcs[23 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter2d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter2d");
#endif
	__asm {jmp mProcs[24 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter2f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter2f");
#endif
	__asm {jmp mProcs[25 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter3d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter3d");
#endif
	__asm {jmp mProcs[26 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter3f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter3f");
#endif
	__asm {jmp mProcs[27 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter4d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter4d");
#endif
	__asm {jmp mProcs[28 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameter4f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameter4f");
#endif
	__asm {jmp mProcs[29 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray1d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray1d");
#endif
	__asm {jmp mProcs[30 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray1f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray1f");
#endif
	__asm {jmp mProcs[31 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray2d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray2d");
#endif
	__asm {jmp mProcs[32 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray2f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray2f");
#endif
	__asm {jmp mProcs[33 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray3d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray3d");
#endif
	__asm {jmp mProcs[34 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray3f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray3f");
#endif
	__asm {jmp mProcs[35 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray4d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray4d");
#endif
	__asm {jmp mProcs[36 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetParameterArray4f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetParameterArray4f");
#endif
	__asm {jmp mProcs[37 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetProgramID_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetProgramID");
#endif
	__asm {jmp mProcs[38 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetTextureEnum_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetTextureEnum");
#endif
	__asm {jmp mProcs[39 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLGetTextureParameter_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLGetTextureParameter");
#endif
	__asm {jmp mProcs[40 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLIsProfileSupported_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLIsProfileSupported");
#endif
	__asm {jmp mProcs[41 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLIsProgramLoaded_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLIsProgramLoaded");
#endif
	__asm {jmp mProcs[42 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLLoadProgram_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLLoadProgram");
#endif
	__asm {jmp mProcs[43 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLRegisterStates_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLRegisterStates");
#endif
	__asm {jmp mProcs[44 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetDebugMode_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetDebugMode");
#endif
	__asm {jmp mProcs[45 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetManageTextureParameters_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetManageTextureParameters");
#endif
	__asm {jmp mProcs[46 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterArraydc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterArraydc");
#endif
	__asm {jmp mProcs[47 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterArraydr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterArraydr");
#endif
	__asm {jmp mProcs[48 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterArrayfc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterArrayfc");
#endif
	__asm {jmp mProcs[49 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterArrayfr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterArrayfr");
#endif
	__asm {jmp mProcs[50 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterdc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterdc");
#endif
	__asm {jmp mProcs[51 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterdr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterdr");
#endif
	__asm {jmp mProcs[52 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterfc_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterfc");
#endif
	__asm {jmp mProcs[53 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetMatrixParameterfr_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetMatrixParameterfr");
#endif
	__asm {jmp mProcs[54 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetOptimalOptions_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetOptimalOptions");
#endif
	__asm {jmp mProcs[55 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter1d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter1d");
#endif
	__asm {jmp mProcs[56 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter1dv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter1dv");
#endif
	__asm {jmp mProcs[57 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter1f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter1f");
#endif
	__asm {jmp mProcs[58 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter1fv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter1fv");
#endif
	__asm {jmp mProcs[59 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter2d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter2d");
#endif
	__asm {jmp mProcs[60 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter2dv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter2dv");
#endif
	__asm {jmp mProcs[61 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter2f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter2f");
#endif
	__asm {jmp mProcs[62 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter2fv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter2fv");
#endif
	__asm {jmp mProcs[63 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter3d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter3d");
#endif
	__asm {jmp mProcs[64 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter3dv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter3dv");
#endif
	__asm {jmp mProcs[65 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter3f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter3f");
#endif
	__asm {jmp mProcs[66 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter3fv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter3fv");
#endif
	__asm {jmp mProcs[67 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter4d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter4d");
#endif
	__asm {jmp mProcs[68 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter4dv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter4dv");
#endif
	__asm {jmp mProcs[69 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter4f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter4f");
#endif
	__asm {jmp mProcs[70 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameter4fv_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameter4fv");
#endif
	__asm {jmp mProcs[71 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray1d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray1d");
#endif
	__asm {jmp mProcs[72 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray1f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray1f");
#endif
	__asm {jmp mProcs[73 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray2d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray2d");
#endif
	__asm {jmp mProcs[74 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray2f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray2f");
#endif
	__asm {jmp mProcs[75 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray3d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray3d");
#endif
	__asm {jmp mProcs[76 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray3f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray3f");
#endif
	__asm {jmp mProcs[77 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray4d_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray4d");
#endif
	__asm {jmp mProcs[78 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterArray4f_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterArray4f");
#endif
	__asm {jmp mProcs[79 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetParameterPointer_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetParameterPointer");
#endif
	__asm {jmp mProcs[80 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetStateMatrixParameter_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetStateMatrixParameter");
#endif
	__asm {jmp mProcs[81 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetTextureParameter_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetTextureParameter");
#endif
	__asm {jmp mProcs[82 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLSetupSampler_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLSetupSampler");
#endif
	__asm {jmp mProcs[83 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLUnbindProgram_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLUnbindProgram");
#endif
	__asm {jmp mProcs[84 * 4]}
}

extern "C" __declspec(naked) void __stdcall cgGLUnloadProgram_wrapper() {
#ifdef _DEBUG
	log_info("calling cgGLUnloadProgram");
#endif
	__asm {jmp mProcs[85 * 4]}
}
