# undofs

## Prerequisites

You must install development headers for fuse. On Fedora (or dnf based Linux OS):
```
dnf install fuse3-devel
```

On Ubuntu (or apt based Linux OS),
```
apt install libfuse3-dev
```


## Mounting the Filesystem

Make underlying filesystem directory: 
```mkdir ~/undofs/undofs-filedata```

Compile the code using `make` and then execute `./undofs <mount-point>`. 

For example, to mount the filesystem at `/mnt/undofs`:

```mkdir /mnt/undofs ; ./undofs -f /mnt/undofs```

To print debug messages using printf use `-f`

You can now view the files and directories by:

```ls /mnt/undofs```


