#include "FileDialog.h" //TODO: FileDialog implementation for linux
#ifdef _WIN32 //windows specific libs
    #include <shobjidl.h> 
    #include <shlobj.h> 
    #define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING //filesystem fix error
    #include <experimental/filesystem>
#endif

std::string OpenFile()
{
    HWND hWnd = nullptr;
	PWSTR pszFilePath;
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));
		if (SUCCEEDED(hr))
		{
			hr = pFileOpen->Show(NULL); // Show the Open dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					if (SUCCEEDED(hr))
					{
						CoTaskMemFree(pszFilePath);

						namespace fs = std::experimental::filesystem;
						fs::path filePath = pszFilePath;
                        std::string path_string{filePath.u8string()};
						return path_string;
					}
					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
	return nullptr;
}