# xv6 on QEMU

## Running xv6

1. **Change Directory and Rebuild Kernel:**
   ```bash
   cd xv6-<your_kernel>
   make
   ```

2. **Launch QEMU:**
   ```bash
   make qemu
   ```

3. **Run Commands:**
   ```bash
   getreadcount
   ls
   cat README
   getreadcount
   ```
