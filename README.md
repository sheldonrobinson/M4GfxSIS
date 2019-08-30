# M4GfxSIS
## System Information Summary Blueprint Library for UE4

M4GfxSIS is provide the following system information summmary at runtime
1. Operation System - name, kernel, version & build
2. CPU - brand, architecture, uarch, bits
3. Processors - cores, threads, frequency, cache topology (L1, L2, L3)
4. GPU - model, vendor, architecture, driver version, memory
5. OpenGL - version, renderer, extensions (if Windows, DirectX support)
6. OpenCL - version, accelerators, profile
7. Vulkan - profile, driver, version
8  Vulkan Runtimes - devices, memory
9. NVMe - size, free space, name, brand, vendor
10. Display - based on EDID
11. Network - NIC, connection speed

This is being develop based on the needs of [**M4Gfx.X**](https://gitlab.com/sheldonrobinson/m4gfxextlib).
The goal is to provide client-side system information to a cloud-gaming server. The cloud-gaming server can use this
information determine the performance profile of the client and optimize the gaming stream accordingly,
