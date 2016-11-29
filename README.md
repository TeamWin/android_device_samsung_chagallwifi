## TWRP device tree for Samsung Galaxy Tab S 10.5 WiFi (chagallwifi)

Add to `.repo/local_manifests/chagallwifi.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
	<project path="device/samsung/chagallwifi" name="android_device_samsung_chagallwifi" remote="TeamWin" revision="android-6.0" />
</manifest>
```

Then run `repo sync` to check it out.

To build:

```sh
. build/envsetup.sh
lunch omni_chagallwifi-eng
make -j5 recoveryimage
```

Kernel sources are available at: https://github.com/jcadduono/android_kernel_samsung_universal5420/tree/twrp-6.0
