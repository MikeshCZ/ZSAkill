#include "cProcessKill.h"
#include <string>
#include <Windows.h>
#include <tlhelp32.h>

cProcessKill::cProcessKill(const std::wstring& processName) : m_processName(processName) {}

bool cProcessKill::killProcess() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(hProcessSnap, &pe32)) {
        CloseHandle(hProcessSnap);
        return false;
    }

    do {
        if (wcscmp(pe32.szExeFile, m_processName.c_str()) == 0) {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
            if (hProcess == NULL) {
                CloseHandle(hProcessSnap);
                return false;
            }

            TerminateProcess(hProcess, 0);
            CloseHandle(hProcess);
            CloseHandle(hProcessSnap);
            return true;
        }
    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
    return false;
}
