#include "version.h"

#include <shlobj.h>	

#include "skse64/PluginAPI.h"
#include "skse64_common/skse_version.h"


// ������
extern "C"
{
	// У��
    bool SKSEPlugin_Query(const SKSEInterface* a_skse, PluginInfo* a_info)
    {
    	// ������־
        IDebugLog::OpenRelative(CSIDL_MYDOCUMENTS, R"(\My Games\Skyrim Special Edition\SKSE\PluginTemplate.log)");
        IDebugLog::SetPrintLevel(IDebugLog::kLevel_Error);
        IDebugLog::SetLogLevel(IDebugLog::kLevel_DebugMessage);

        _MESSAGE("PluginTemplate %s", PLTP_VERSION);

    	// ��Ϣ��ֵ
        a_info->infoVersion = PluginInfo::kInfoVersion;
        a_info->name = "PluginTemplate";
        a_info->version = 1000;

    	// У�黷��
        if (a_skse->isEditor) {
            _MESSAGE("loaded in editor, marking as incompatible");

            return false;
        }

    	// У��汾
        if (a_skse->runtimeVersion != RUNTIME_VERSION_1_5_97) {
            _FATALERROR("unsupported runtime version %08x", a_skse->runtimeVersion);

            return false;
        }

        return true;
    }


	// ����
    bool SKSEPlugin_Load(const SKSEInterface* a_skse)
    {
        _MESSAGE("PluginTemplate loaded");
    	
        _MESSAGE("Hello SKSE64 !");
    	
        return true;
    }
}