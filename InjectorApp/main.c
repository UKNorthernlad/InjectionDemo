#include <stdio.h>
#include <Windows.h>

int main()
{
    // path to our dll
    LPCSTR DllPath = "C:\\temp\\InjectionDemo\\x64\\Debug\\test.dll";

    // Open a handle to target process
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 4384);

    // Allocate memory for the dllpatch in the target process
    // length of the path string + null terminator

    LPVOID pDllPath = VirtualAllocEx(hProcess, 0, strlen(DllPath) + 1, MEM_COMMIT, PAGE_READWRITE);

    // Write the patch to the address of the memory just allocated in the target process
    WriteProcessMemory(hProcess, pDllPath, (LPVOID)DllPath, strlen(DllPath) + 1, 0);

    // Create a thread in the remote process.
    HANDLE hLoadThread = CreateRemoteThread(
        hProcess,
        0,
        0,
        (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"),"LoadLibraryA"),
        pDllPath,
        0,
        0);

    // Wait for execution of loader thread
    WaitForSingleObject(hLoadThread, INFINITE);

    printf("DLL path allocated at 0x%p \n", pDllPath);
    
    VirtualFreeEx(hProcess, pDllPath, strlen(DllPath) + 1, MEM_RELEASE);
    
    return 0;
}

