#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
 #        .---.         .-----------
 #       /     \  __  /    ------
 #      / /     \(  )/    -----   (`-')  _ _(`-')              <-. (`-')_
 #     //////    '\/ `   ---      ( OO).-/( (OO ).->     .->      \( OO) )     .->
 #    //// / //  :   : ---      (,------. \    .'_ (`-')----. ,--./ ,--/  ,--.'  ,-.
 #   // /   /  / `\/ '--         |  .---' '`'-..__)( OO).-. ' |   \ |  | (`-')'.'  /
 #  //          //..\\\\          (|  '--.  |  |  ' |( _) | | | |  . '|  |)(OO \    /
 # ============UU====UU====      |  .--'  |  |  / : \|  |)| | |  |\    |  |  /   /)
 #             '//||\\\`          |  `---. |  '-'  /  '  '-' ' |  | \   |  `-/   /`
 #               ''``            `------' `------'    `-----' `--'  `--'    `--'
 # ######################################################################################
 #
 # Author: edony - edonyzpc@gmail.com
 #
 # twitter : @edonyzpc
 #
 # Last modified: 2017-03-15 22:54
 #
 # Filename: codecov.py
 #
 # Description: All Rights Are Reserved
 #
"""
import os
import sys
try:
    from subprocess import getstatusoutput
except ImportError:
    from commands import getstatusoutput

exefiles = ['./colorprint', './splitstr', './join']
def gcno_file():
    cmd = 'ls -1'
    stat, output = getstatusoutput(cmd)
    gnco_files = [item for item in output.split() if item.endswith('gcno')]
    gncos = [item.split('-')[1] for item in gnco_files]
    for idx, item in enumerate(gnco_files):
        os.system('mv ' + item + ' ' + gncos[idx])


def gcda_file():
    cmd = 'ls -1'
    stat, output = getstatusoutput(cmd)
    gcda_files = [item for item in output.split() if item.endswith('gcda')]
    gcdas = [item.split('-')[1] for item in gcda_files]
    for idx, item in enumerate(gcda_files):
        os.system('mv ' + item + ' ' + gcdas[idx])

if __name__ == "__main__":
    if sys.argv[1] == 'gcno':
        gcno_file()
    elif sys.argv[1] == 'gcda':
        gcda_file()
    elif sys.argv[1] == 'exec':
        for cmd in exefiles:
            os.system(cmd)
