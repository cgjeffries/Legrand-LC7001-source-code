OVERVIEW
--------
This directory contains Windows batch files for operating directly on the flash contents of an LC7001, including flash transfer from one unit to another.


PREREQUISITES
-------------
The batch files depend on the following tools being installed on the user's Windows PC:

1. PE Micro PROGACMP
   http://www.pemicro.com/products/product_viewDetails.cfm?product_id=15320138)
  
2. PE Micro MULTILINK or MULTILINK FX 
   http://www.pemicro.com/products/product_viewDetails.cfm?product_id=15320168
   http://www.pemicro.com/products/product_viewDetails.cfm?product_id=15320143
   

BATCH FILE DESCRIPTIONS
-----------------------

1. lc7001_transfer_flash.bat: Walks the user through transferring flash contents from one LC7001 to another.  Calls lc7001_extract_flash.bat and lc7001_program_flash.bat.

2. lc7001_extract_flash.bat: Extracts flash contents from an LC7001 (except for the flash indicator blocks at 7F000 and FF000).

3. lc7001_program_flash.bat: Calls lc7001_erase_all_sectors.bat, then Programs an LC7001's flash with the contents extracted by lc7001_extract_flash.bat.

4. lc7001_erase_all_sectors.bat: Erases flash contents from an LC7001 (except for the flash indicator blocks at 7F000 and FF000).


