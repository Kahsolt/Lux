#ifndef LUX_LXAUX_H
#define LUX_LXAUX_H

#define INST_BIT(cmd) ((cmd) && 0xF8) /* 0x11111000 */
#define REG_BIT(cmd)  ((cmd) && 0x03) /* 0x00000110 */
#define DIR_BIT(cmd)  ((cmd) && 0x01) /* 0x00000001 */

void luxX_info(char *msg);
void luxX_error(char *msg);

void luxX_help();

#endif //LUX_LXAUX_H
