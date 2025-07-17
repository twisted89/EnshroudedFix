# Enshrouded Dedicated Server CPU Fix

This project attempts to reduce the CPU burden of the dedicated server by adding a tick rate.

# Usage

 - Compile or download the latest release
 - Copy dbghelp.dll (and vcruntime140.dll if you don't have the c++
   redist or you're using wine/proton) into the Enshrouded Dedicated
   Server install directory next to enshrouded_server.exe
 - If running in wine/proton set the environment variable WINEDLLOVERRIDES="dbghelp.dll=n,b"
 - Run enshrouded_server.exe - you should see "Enshrouded Fix loaded!
   Hooks successful!" at the top of the log