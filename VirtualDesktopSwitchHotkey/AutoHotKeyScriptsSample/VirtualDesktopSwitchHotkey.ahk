;
; AutoHotkey Version: 1.x
; Language:       English
; Platform:       Win9x/NT
; Author:         nullpo_head <abc.tkys+pub@gmail.com>
;
; Script Function:
;	Map Win + Ctrl + Number to "Switch to Nth Virtual Desktop"
;

#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.

FileInstall, VirtualDesktopSwitcher.exe, VirtualDesktopSwitcher.exe 
#^1::Run, VirtualDesktopSwitcher.exe 0
#^2::Run, VirtualDesktopSwitcher.exe 1
#^3::Run, VirtualDesktopSwitcher.exe 2
#^4::Run, VirtualDesktopSwitcher.exe 3
#^5::Run, VirtualDesktopSwitcher.exe 4
#^6::Run, VirtualDesktopSwitcher.exe 5
#^7::Run, VirtualDesktopSwitcher.exe 6
#^8::Run, VirtualDesktopSwitcher.exe 7
#^9::Run, VirtualDesktopSwitcher.exe 8
