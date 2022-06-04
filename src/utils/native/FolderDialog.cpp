#include "FolderDialog.h"
#ifdef _WIN32 //windows specific libs
    #include <shobjidl.h> 
    #include <shlobj.h> 
    #define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING //filesystem fix error
    #include <experimental/filesystem>
#endif
std::string OpenFolder()
{
    LPCWSTR l_folder_path;
	TCHAR path[MAX_PATH];
	BROWSEINFO bi = { 0 };
	bi.lpszTitle = "All Folders Automatically Recursed.";
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

	if (pidl != 0)
	{
		// get the name of the folder and put it in path
		SHGetPathFromIDList(pidl, path);
		SetCurrentDirectory(path);

		std::string folder_path = std::string(path);
		//Begin the search
		return folder_path;
		// free memory used
		IMalloc* imalloc = 0;
		if (SUCCEEDED(SHGetMalloc(&imalloc)))
		{
			imalloc->Free(pidl);
			imalloc->Release();
		}
	}
	return nullptr;
}
