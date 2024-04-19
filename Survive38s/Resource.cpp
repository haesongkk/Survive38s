#include "Header.h"
#include "Resource.h"

#include <filesystem>
#include <istream>
#include <fstream>
using namespace filesystem;

map<wstring, wstring> txtResource;

void LoadTxt()
{
    // 현재 경로 (= 작업 디렉토리)
    path current_dir = current_path();

    // recursive_ : 모든 하위 디렉토리 재귀적으로 탐색
    for (const auto& entry : recursive_directory_iterator(current_dir))
    {
        if (entry.path().extension() == ".txt")
        {
            wifstream wfile(entry.path());
            assert(wfile);

            wstring wstr;
            wstr.assign(
                (istreambuf_iterator<wchar_t>(wfile)),
                istreambuf_iterator<wchar_t>());

            txtResource[entry.path().stem().wstring()] = wstr;

        }
    }
}

wstring GetTxt(wstring _fileName)
{
    return txtResource[_fileName];
}
