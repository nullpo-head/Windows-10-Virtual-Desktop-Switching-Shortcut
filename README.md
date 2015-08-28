# Windows 10 Switch to Nth Virtual Desktop Shortcut Key

## What is this?

This is a small hotkey tool for mapping Ctrl + Win + number keys to  "Switch to Nth Virtual Desktop", which is missing in the Windows 10 virtual desktop shortcuts.  
  

## How to use

Just run VirtualDesktopSwitchHotkey.exe in VirtualDesktopSwitchHotkey folder.  
Copy VirtualDesktopSwitchHotkey.exe into your startup if you like it.  
This tool uses AutoHotKey (http://www.autohotkey.com/) to map hotkeys. If you would like to change the key mapping, install it and rewrite an AutoHotKey script in VirtualDesktopSwitchHotkey\AutoHotKeyScriptsSample.  

## Implementation

VirtualDesktopSwitcher.exe is the core of this tool. It reads a number from command line arguments and calls Windows 10 private API to switch the virtual desktop.  
NickoTin investigated the internal API of virtual desktops and published it on http://www.cyberforum.ru/blogs/105416/blog3671.html . All API interfaces VirtualDesktopSwitcher uses are based on it. Thanks for great post, NickoTin!! 