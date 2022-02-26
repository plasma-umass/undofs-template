# undofs

## Prerequisites

You must install development headers for fuse. On Fedora (or dnf based Linux OS):
```
dnf install fuse-devel
```

On Ubuntu (or apt based Linux OS),
```
apt install libfuse-dev
```

## Mounting the Filesystem

Compile the code using `make` and then execute `./undofs <mount-point>`. 
For example, to mount the filesystem at `/mnt/undofs`:

```mkdir /mnt/undofs ; ./undofs /mnt/undofs```

You can now view the files and directories by:

```ls /mnt/undofs```


