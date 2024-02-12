# InjectionDemo

The **InjectorApp** will load the **testDLL.dll** dynamically into another process.

From `main.c` file for *InjectorApp* project we see in line 10 that it is attempting to open another process `4384` in preparation for the injection.

```
// Open a handle to target process
HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 4384);
```