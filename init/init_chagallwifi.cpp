/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "util.h"

#define DEVICE_NAME "chagall"

static void set_device(const char *radio,
		       const char *region,
		       const char *model)
{
	char device[16], name[16];

	sprintf(device, "%s%s", DEVICE_NAME, radio);
	sprintf(name, "%s%s", device, region);

	property_set("ro.product.name", name);
	property_set("ro.product.device", device);
	property_set("ro.product.model", model);
}

void vendor_load_properties()
{
	char bootloader[PROP_VALUE_MAX];

	property_get("ro.bootloader", bootloader);

	if (strstr(bootloader, "T800")) {
		/* WiFi */
		set_device("wifi", "xx", "SM-T800");
	} else if (strstr(bootloader, "T801")) {
		/* 3G */
		set_device("3g", "xx", "SM-T801");
	} else if (strstr(bootloader, "T807A")) {
		/* AT&T */
		set_device("lte", "att", "SM-T807A");
	} else if (strstr(bootloader, "T807P")) {
		/* Sprint */
		set_device("lte", "spr", "SM-T807P");
	} else if (strstr(bootloader, "T807T")) {
		/* T-Mobile */
		set_device("lte", "tmo", "SM-T807T");
	} else if (strstr(bootloader, "T807R4")) {
		/* US Cellular */
		set_device("lte", "usc", "SM-T807R4");
	} else if (strstr(bootloader, "T807V")) {
		/* Verizon */
		set_device("lte", "vzw", "SM-T807V");
	} else if (strstr(bootloader, "T805K")) {
		/* Olleh (KT) */
		set_device("lte", "ktt", "SM-T805K");
	} else if (strstr(bootloader, "T805L")) {
		/* LG Uplus */
		set_device("lte", "lgt", "SM-T805L");
	} else if (strstr(bootloader, "T805S")) {
		/* SK Telecom */
		set_device("lte", "skt", "SM-T805S");
	} else if (strstr(bootloader, "T807D")) {
		/* DoCoMo */
		set_device("lte", "dcm", "SM-T807D");
	} else if (strstr(bootloader, "T805M")) {
		/* South Americas */
		set_device("lte", "ub", "SM-T805M");
	} else if (strstr(bootloader, "T805C")) {
		/* China */
		set_device("lte", "zc", "SM-T805C");
	} else if (strstr(bootloader, "T805W")) {
		/* Canada */
		set_device("lte", "vl", "SM-T805W");
	} else if (strstr(bootloader, "T805YZ")) {
		/* Taiwan */
		set_device("lte", "zt", "SM-T805Y");
	} else if (strstr(bootloader, "T805Y")) {
		/* Oceanic */
		set_device("lte", "do", "SM-T805Y");
	} else {
		/* all other variants become International LTE */
		set_device("lte", "xx", "SM-T805");
	}
}
