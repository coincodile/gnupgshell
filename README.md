# Gnupg Shell

GnuPG Shell is a software tool that keeps information safe by using the strong 
protection that OpenPGP standard offers. GnuPG Shell is a cross platform 
graphical front end for GNU Privacy Guard.


GnuPG Shell is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

## Installation

You need the GNU development tools plus the GTK+ library, version
1.3 or higher and wxGTK, version 2.8.4 or higher, installed on your 
system. Clone the project source, `cd' into the directory, compile, 
and install GnuPG Shell:

    cd gnupgshell
    autoreconf
    ./configure
    make
    su -c "make install"

In order to do anything useful with GnuPG Shell you also need the
GNU Privacy Guard (GnuPG) installed - see http://www.gnupg.org.

For more information about how to install see INSTALL in source directory.

## Report bugs

Please report any problems on the project Github page.

