## O que é LVM?
&nbsp; *Logical Volume Manager* (LVM) é uma ferramenta de gerenciamento de volume lógico, sendo capaz de efetuar alocação de discos, *mirroring* e *resizing* nos volumes lógicos.

&nbsp; Com o uso do **LVM**, um ou mais *Hard Drives* (Discos rígidos) podem ser alocados à um ou mais _**Physical Volumes**_ (PV). Os **PVs** são então combinados em volumes lógicos, com exceção da partição `/boot`, o qual não pode pertencer à um volume lógico, uma vez que o *boot loader* não é capaz de ler os mesmos. Caso a partição `/` (root) esteja em um Volume Lógico, é necessário criar uma partição `/boot` separada a mesma.
