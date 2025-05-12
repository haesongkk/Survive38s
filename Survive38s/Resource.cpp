#include "Header.h"
#include "Resource.h"

#include <filesystem>
#include <istream>
#include <fstream>
using namespace filesystem;

map<wstring, wstring> txtResource;

void LoadTxt()
{
    // ���� ��� (= �۾� ���丮)
    path current_dir = current_path();

    // recursive_ : ��� ���� ���丮 ��������� Ž��
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
