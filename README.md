# My setup for the Anne Pro 2 QMK

## Setup

* Create a folder and `cd` into it
* Run `git clone git@github.com:OpenAnnePro/qmk_firmware.git`
* Run `git clone git@github.com:OpenAnnePro/AnnePro2-Shine.git`
* Run `git clone git@github.com:OpenAnnePro/AnnePro2-Tools.git`
* Run `git clone git@github.com:matdurand/qmk-keymap.git`

You now have a folder with 4 subfolder. The source for this repo is stored into the `qmk-keymap` folder.

### Layout

This keymap works in pair with the following keyboard layouts configured in your OS:
* Linux: French (Canada)
* MacOS: [Canadien Francais 0.12.1](https://github.com/ergosteur/cf-keylayout)
## Uploading the keymap

To upload the keymap, run `update-firmware.sh`. To make it faster, if you need to upload multiple times for testing,
you should:
* delete the other keymaps in `qmk_firmware/keyboards/annepro2/keymaps/`
* remove the line in the script about "Building anne pro 2 tools", you only need that once
* remove the lines about the Shine firmware for LED, you only need that once

## LEDs

By default, AnnePro2-Shine comes with a couple of led patterns. I usually only need the `white` pattern. To remove the 
others, just comment the lines in `AnnePro2-Shine/source/settings.c`

## Other considerations

If you get in trouble and the flashing is interrupted, just unplug the anne pro 2, and hold ESC while plugging the keyboard.
It will get in IAP mode and you will be able to re-flash.

### Linux

By default, the French (Canada) keyboard is only using the dead-key version of the backtick. 
It's often useful, for example in slack or javascript, to be able to create a single key backtick. 
The mac keyboard layout support both the dead-key and non-dead-key of the backtick, which is supported by our custom 
layout here, but not the Linux layout. Do change that, just edit `/usr/share/X11/xkb/symbols/ca`, 
and for the French (Canada) keyboard, change this line
```
 key <AC11>	{ [dead_grave, dead_grave,  braceleft ]	};
```
by this line
```
 key <AC11>	{ [dead_grave,      grave,  braceleft ]	};
```

Then to reload the keyboard, run
```
sudo dpkg-reconfigure xkb-data
```

You may need to restart after.