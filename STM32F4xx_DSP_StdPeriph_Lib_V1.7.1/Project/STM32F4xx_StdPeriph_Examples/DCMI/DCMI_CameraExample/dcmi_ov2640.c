/**
  ******************************************************************************
  * @file    DCMI/DCMI_CameraExample/dcmi_ov2640.c
  * @author  MCD Application Team
  * @version V1.7.0
  * @date    22-April-2016
  * @brief   This file includes the driver for OV2640 Camera module mounted on
  *          STM324xG-EVAL and STM32437I-EVAL evaluation boards.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "dcmi_ov2640.h"

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup DCMI_CameraExample
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define  TIMEOUT  2

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* QQVGA 160x120 */
const char OV2640_QQVGA[][2]=
{
  0xff, 0x00,
  0x2c, 0xff,
  0x2e, 0xdf,
  0xff, 0x01,
  0x3c, 0x32,
  0x11, 0x00,
  0x09, 0x02,
  0x03, 0xcf,
  0x04, 0x08,
  0x13, 0xe5,
  0x14, 0x48,
  0x2c, 0x0c,
  0x33, 0x78,
  0x3a, 0x33,
  0x3b, 0xfb,
  0x3e, 0x00,
  0x43, 0x11,
  0x16, 0x10,
  0x39, 0x02,
  0x35, 0x88,
  0x22, 0x0a,
  0x37, 0x40,
  0x23, 0x00,
  0x34, 0xa0,
  0x36, 0x1a,
  0x06, 0x02,
  0x07, 0xc0,
  0x0d, 0xb7,
  0x0e, 0x01,
  0x4c, 0x00,
  0x4a, 0x81,
  0x21, 0x99,
  0x24, 0x3a,
  0x25, 0x32,
  0x26, 0x82,
  0x5c, 0x00,
  0x63, 0x00,
  0x5d, 0x55,
  0x5e, 0x7d,
  0x5f, 0x7d,
  0x60, 0x55,
  0x61, 0x70,
  0x62, 0x80,
  0x7c, 0x05,
  0x20, 0x80,
  0x28, 0x30,
  0x6c, 0x00,
  0x6d, 0x80,
  0x6e, 0x00,
  0x70, 0x02,
  0x71, 0x96,
  0x73, 0xe1,
  0x3d, 0x34,
  0x5a, 0x57,
  0x4f, 0xbb,
  0x50, 0x9c,
  0x0f, 0x43,
  0xff, 0x00,
  0xe5, 0x7f,
  0xf9, 0xc0,
  0x41, 0x24,
  0xe0, 0x14,
  0x76, 0xff,
  0x33, 0xa0,
  0x42, 0x20,
  0x43, 0x18,
  0x4c, 0x00,
  0x87, 0xd0,
  0x88, 0x3f,
  0xd7, 0x03,
  0xd9, 0x10,
  0xd3, 0x82,
  0xc8, 0x08,
  0xc9, 0x80,
  0x7c, 0x00,
  0x7d, 0x02,
  0x7c, 0x03,
  0x7d, 0x48,
  0x7d, 0x48,
  0x7c, 0x08,
  0x7d, 0x20,
  0x7d, 0x10,
  0x7d, 0x0e,
  0x90, 0x00,
  0x91, 0x0e,
  0x91, 0x1a,
  0x91, 0x31,
  0x91, 0x5a,
  0x91, 0x69,
  0x91, 0x75,
  0x91, 0x7e,
  0x91, 0x88,
  0x91, 0x8f,
  0x91, 0x96,
  0x91, 0xa3,
  0x91, 0xaf,
  0x91, 0xc4,
  0x91, 0xd7,
  0x91, 0xe8,
  0x91, 0x20,
  0x92, 0x00,
  0x93, 0x06,
  0x93, 0xe3,
  0x93, 0x05,
  0x93, 0x05,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x96, 0x00,
  0x97, 0x08,
  0x97, 0x19,
  0x97, 0x02,
  0x97, 0x0c,
  0x97, 0x24,
  0x97, 0x30,
  0x97, 0x28,
  0x97, 0x26,
  0x97, 0x02,
  0x97, 0x98,
  0x97, 0x80,
  0x97, 0x00,
  0x97, 0x00,
  0xc3, 0xed,
  0xa4, 0x00,
  0xa8, 0x00,
  0xbf, 0x00,
  0xba, 0xf0,
  0xbc, 0x64,
  0xbb, 0x02,
  0xb6, 0x3d,
  0xb8, 0x57,
  0xb7, 0x38,
  0xb9, 0x4e,
  0xb3, 0xe8,
  0xb4, 0xe1,
  0xb5, 0x66,
  0xb0, 0x67,
  0xb1, 0x5e,
  0xb2, 0x04,
  0xc7, 0x00,
  0xc6, 0x51,
  0xc5, 0x11,
  0xc4, 0x9c,
  0xcf, 0x02,
  0xa6, 0x00,
  0xa7, 0xe0,
  0xa7, 0x10,
  0xa7, 0x1e,
  0xa7, 0x21,
  0xa7, 0x00,
  0xa7, 0x28,
  0xa7, 0xd0,
  0xa7, 0x10,
  0xa7, 0x16,
  0xa7, 0x21,
  0xa7, 0x00,
  0xa7, 0x28,
  0xa7, 0xd0,
  0xa7, 0x10,
  0xa7, 0x17,
  0xa7, 0x21,
  0xa7, 0x00,
  0xa7, 0x28,
  0xc0, 0xc8,
  0xc1, 0x96,
  0x86, 0x1d,
  0x50, 0x00,
  0x51, 0x90,
  0x52, 0x18,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x88,
  0x57, 0x00,
  0x5a, 0x90,
  0x5b, 0x18,
  0x5c, 0x05,
  0xc3, 0xef,
  0x7f, 0x00,
  0xda, 0x00,
  0xe5, 0x1f,
  0xe1, 0x67,
  0xe0, 0x00,
  0xdd, 0xff,
  0x05, 0x00,
  0xff, 0x01,
  0xff, 0x01,
  0x12, 0x00,
  0x17, 0x11,
  0x18, 0x75,
  0x19, 0x01,
  0x1a, 0x97,
  0x32, 0x36,
  0x4f, 0xbb,
  0x6d, 0x80,
  0x3d, 0x34,
  0x39, 0x02,
  0x35, 0x88,
  0x22, 0x0a,
  0x37, 0x40,
  0x23, 0x00,
  0x34, 0xa0,
  0x36, 0x1a,
  0x06, 0x02,
  0x07, 0xc0,
  0x0d, 0xb7,
  0x0e, 0x01,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0x8c, 0x00,
  0x87, 0xd0,
  0xe0, 0x00,
  0xff, 0x00,
  0xe0, 0x14,
  0xe1, 0x77,
  0xe5, 0x1f,
  0xd7, 0x03,
  0xda, 0x10,
  0xe0, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0xc8,
  0xc1, 0x96,
  0x86, 0x1d,
  0x50, 0x00,
  0x51, 0x90,
  0x52, 0x2c,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x88,
  0x57, 0x00,
  0x5a, 0x90,
  0x5b, 0x2c,
  0x5c, 0x05,
  0xe0, 0x00,
  0xd3, 0x04,
  0xff, 0x00,
  0xc3, 0xef,
  0xa6, 0x00,
  0xa7, 0xdd,
  0xa7, 0x78,
  0xa7, 0x7e,
  0xa7, 0x24,
  0xa7, 0x00,
  0xa7, 0x25,
  0xa6, 0x06,
  0xa7, 0x20,
  0xa7, 0x58,
  0xa7, 0x73,
  0xa7, 0x34,
  0xa7, 0x00,
  0xa7, 0x25,
  0xa6, 0x0c,
  0xa7, 0x28,
  0xa7, 0x58,
  0xa7, 0x6d,
  0xa7, 0x34,
  0xa7, 0x00,
  0xa7, 0x25,
  0xff, 0x00,
  0xe0, 0x04,
  0xe1, 0x67,
  0xe5, 0x1f,
  0xd7, 0x01,
  0xda, 0x08,
  0xda, 0x09,
  0xe0, 0x00,
  0x98, 0x00,
  0x99, 0x00,
  0xff, 0x01,
  0x04, 0x28,
  0xff, 0x01,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x4f, 0xca,
  0x50, 0xa8,
  0x5a, 0x23,
  0x6d, 0x00,
  0x39, 0x12,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0x64,
  0xc1, 0x4b,
  0x86, 0x35,
  0x50, 0x92,
  0x51, 0xc8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x57, 0x00,
  0x5a, 0x28,
  0x5b, 0x1e,
  0x5c, 0x00,
  0xe0, 0x00,
  0xff, 0x01,
  0x11, 0x00,
  0x3d, 0x38,
  0x2d, 0x00,
  0x50, 0x65,
  0xff, 0x00,
  0xd3, 0x04,
  0x7c, 0x00,
  0x7d, 0x04,
  0x7c, 0x09,
  0x7d, 0x28,
  0x7d, 0x00,
};

/* QVGA 320x240 */
const unsigned char OV2640_QVGA[][2]=
{
  0xff, 0x00,
  0x2c, 0xff,
  0x2e, 0xdf,
  0xff, 0x01,
  0x3c, 0x32,
  0x11, 0x00,
  0x09, 0x02,
  0x04, 0x28,
  0x13, 0xe5,
  0x14, 0x48,
  0x2c, 0x0c,
  0x33, 0x78,
  0x3a, 0x33,
  0x3b, 0xfB,
  0x3e, 0x00,
  0x43, 0x11,
  0x16, 0x10,
  0x4a, 0x81,
  0x21, 0x99,
  0x24, 0x40,
  0x25, 0x38,
  0x26, 0x82,
  0x5c, 0x00,
  0x63, 0x00,
  0x46, 0x3f,
  0x0c, 0x3c,
  0x61, 0x70,
  0x62, 0x80,
  0x7c, 0x05,
  0x20, 0x80,
  0x28, 0x30,
  0x6c, 0x00,
  0x6d, 0x80,
  0x6e, 0x00,
  0x70, 0x02,
  0x71, 0x94,
  0x73, 0xc1,
  0x3d, 0x34,
  0x5a, 0x57,
  0x12, 0x00,
  0x11, 0x00,
  0x17, 0x11,
  0x18, 0x75,
  0x19, 0x01,
  0x1a, 0x97,
  0x32, 0x36,
  0x03, 0x0f,
  0x37, 0x40,
  0x4f, 0xbb,
  0x50, 0x9c,
  0x5a, 0x57,
  0x6d, 0x80,
  0x6d, 0x38,
  0x39, 0x02,
  0x35, 0x88,
  0x22, 0x0a,
  0x37, 0x40,
  0x23, 0x00,
  0x34, 0xa0,
  0x36, 0x1a,
  0x06, 0x02,
  0x07, 0xc0,
  0x0d, 0xb7,
  0x0e, 0x01,
  0x4c, 0x00,
  0xff, 0x00,
  0xe5, 0x7f,
  0xf9, 0xc0,
  0x41, 0x24,
  0xe0, 0x14,
  0x76, 0xff,
  0x33, 0xa0,
  0x42, 0x20,
  0x43, 0x18,
  0x4c, 0x00,
  0x87, 0xd0,
  0x88, 0x3f,
  0xd7, 0x03,
  0xd9, 0x10,
  0xd3, 0x82,
  0xc8, 0x08,
  0xc9, 0x80,
  0x7d, 0x00,
  0x7c, 0x03,
  0x7d, 0x48,
  0x7c, 0x08,
  0x7d, 0x20,
  0x7d, 0x10,
  0x7d, 0x0e,
  0x90, 0x00,
  0x91, 0x0e,
  0x91, 0x1a,
  0x91, 0x31,
  0x91, 0x5a,
  0x91, 0x69,
  0x91, 0x75,
  0x91, 0x7e,
  0x91, 0x88,
  0x91, 0x8f,
  0x91, 0x96,
  0x91, 0xa3,
  0x91, 0xaf,
  0x91, 0xc4,
  0x91, 0xd7,
  0x91, 0xe8,
  0x91, 0x20,
  0x92, 0x00,
  0x93, 0x06,
  0x93, 0xe3,
  0x93, 0x02,
  0x93, 0x02,
  0x93, 0x00,
  0x93, 0x04,
  0x93, 0x00,
  0x93, 0x03,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x96, 0x00,
  0x97, 0x08,
  0x97, 0x19,
  0x97, 0x02,
  0x97, 0x0c,
  0x97, 0x24,
  0x97, 0x30,
  0x97, 0x28,
  0x97, 0x26,
  0x97, 0x02,
  0x97, 0x98,
  0x97, 0x80,
  0x97, 0x00,
  0x97, 0x00,
  0xc3, 0xef,
  0xff, 0x00,
  0xba, 0xdc,
  0xbb, 0x08,
  0xb6, 0x24,
  0xb8, 0x33,
  0xb7, 0x20,
  0xb9, 0x30,
  0xb3, 0xb4,
  0xb4, 0xca,
  0xb5, 0x43,
  0xb0, 0x5c,
  0xb1, 0x4f,
  0xb2, 0x06,
  0xc7, 0x00,
  0xc6, 0x51,
  0xc5, 0x11,
  0xc4, 0x9c,
  0xbf, 0x00,
  0xbc, 0x64,
  0xa6, 0x00,
  0xa7, 0x1e,
  0xa7, 0x6b,
  0xa7, 0x47,
  0xa7, 0x33,
  0xa7, 0x00,
  0xa7, 0x23,
  0xa7, 0x2e,
  0xa7, 0x85,
  0xa7, 0x42,
  0xa7, 0x33,
  0xa7, 0x00,
  0xa7, 0x23,
  0xa7, 0x1b,
  0xa7, 0x74,
  0xa7, 0x42,
  0xa7, 0x33,
  0xa7, 0x00,
  0xa7, 0x23,
  0xc0, 0xc8,
  0xc1, 0x96,
  0x8c, 0x00,
  0x86, 0x3d,
  0x50, 0x92,
  0x51, 0x90,
  0x52, 0x2c,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x88,
  0x5a, 0x50,
  0x5b, 0x3c,
  0x5c, 0x00,
  0xd3, 0x04,
  0x7f, 0x00,
  0xda, 0x00,
  0xe5, 0x1f,
  0xe1, 0x67,
  0xe0, 0x00,
  0xdd, 0x7f,
  0x05, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0xc8,
  0xc1, 0x96,
  0x86, 0x3d,
  0x50, 0x92,
  0x51, 0x90,
  0x52, 0x2c,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x88,
  0x57, 0x00,
  0x5a, 0x50,
  0x5b, 0x3c,
  0x5c, 0x00,
  0xd3, 0x04,
  0xe0, 0x00,
  0xFF, 0x00,
  0x05, 0x00,
  0xDA, 0x08,
  0xda, 0x09,
  0x98, 0x00,
  0x99, 0x00,
  0x00, 0x00,
};

const unsigned char OV2640_JPEG_INIT[][2]=
{
  0xff, 0x00,
  0x2c, 0xff,
  0x2e, 0xdf,
  0xff, 0x01,
  0x3c, 0x32,
  0x11, 0x30,
  0x09, 0x02,
  0x04, 0x28,
  0x13, 0xe5,
  0x14, 0x48,
  0x2c, 0x0c,
  0x33, 0x78,
  0x3a, 0x33,
  0x3b, 0xfB,
  0x3e, 0x00,
  0x43, 0x11,
  0x16, 0x10,
  0x39, 0x92,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0x48, 0x00,
  0x5B, 0x00,
  0x42, 0x03,
  0x4a, 0x81,
  0x21, 0x99,
  0x24, 0x40,
  0x25, 0x38,
  0x26, 0x82,
  0x5c, 0x00,
  0x63, 0x00,
  0x61, 0x70,
  0x62, 0x80,
  0x7c, 0x05,
  0x20, 0x80,
  0x28, 0x30,
  0x6c, 0x00,
  0x6d, 0x80,
  0x6e, 0x00,
  0x70, 0x02,
  0x71, 0x94,
  0x73, 0xc1,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x37, 0xc0,
  0x4f, 0x60,
  0x50, 0xa8,
  0x6d, 0x00,
  0x3d, 0x38,
  0x46, 0x3f,
  0x4f, 0x60,
  0x0c, 0x3c,
  0xff, 0x00,
  0xe5, 0x7f,
  0xf9, 0xc0,
  0x41, 0x24,
  0xe0, 0x14,
  0x76, 0xff,
  0x33, 0xa0,
  0x42, 0x20,
  0x43, 0x18,
  0x4c, 0x00,
  0x87, 0xd5,
  0x88, 0x3f,
  0xd7, 0x03,
  0xd9, 0x10,
  0xd3, 0x82,
  0xc8, 0x08,
  0xc9, 0x80,
  0x7c, 0x00,
  0x7d, 0x00,
  0x7c, 0x03,
  0x7d, 0x48,
  0x7d, 0x48,
  0x7c, 0x08,
  0x7d, 0x20,
  0x7d, 0x10,
  0x7d, 0x0e,
  0x90, 0x00,
  0x91, 0x0e,
  0x91, 0x1a,
  0x91, 0x31,
  0x91, 0x5a,
  0x91, 0x69,
  0x91, 0x75,
  0x91, 0x7e,
  0x91, 0x88,
  0x91, 0x8f,
  0x91, 0x96,
  0x91, 0xa3,
  0x91, 0xaf,
  0x91, 0xc4,
  0x91, 0xd7,
  0x91, 0xe8,
  0x91, 0x20,
  0x92, 0x00,
  0x93, 0x06,
  0x93, 0xe3,
  0x93, 0x05,
  0x93, 0x05,
  0x93, 0x00,
  0x93, 0x04,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x93, 0x00,
  0x96, 0x00,
  0x97, 0x08,
  0x97, 0x19,
  0x97, 0x02,
  0x97, 0x0c,
  0x97, 0x24,
  0x97, 0x30,
  0x97, 0x28,
  0x97, 0x26,
  0x97, 0x02,
  0x97, 0x98,
  0x97, 0x80,
  0x97, 0x00,
  0x97, 0x00,
  0xc3, 0xed,
  0xa4, 0x00,
  0xa8, 0x00,
  0xc5, 0x11,
  0xc6, 0x51,
  0xbf, 0x80,
  0xc7, 0x10,
  0xb6, 0x66,
  0xb8, 0xA5,
  0xb7, 0x64,
  0xb9, 0x7C,
  0xb3, 0xaf,
  0xb4, 0x97,
  0xb5, 0xFF,
  0xb0, 0xC5,
  0xb1, 0x94,
  0xb2, 0x0f,
  0xc4, 0x5c,
  0xc0, 0x64,
  0xc1, 0x4B,
  0x8c, 0x00,
  0x86, 0x3D,
  0x50, 0x00,
  0x51, 0xC8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x5a, 0xC8,
  0x5b, 0x96,
  0x5c, 0x00,
  0xd3, 0x7f,
  0xc3, 0xed,
  0x7f, 0x00,
  0xda, 0x00,
  0xe5, 0x1f,
  0xe1, 0x67,
  0xe0, 0x00,
  0xdd, 0x7f,
  0x05, 0x00,

  0x12, 0x40,
  0xd3, 0x7f,
  0xc0, 0x16,
  0xC1, 0x12,
  0x8c, 0x00,
  0x86, 0x3d,
  0x50, 0x00,
  0x51, 0x2C,
  0x52, 0x24,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x5A, 0x2c,
  0x5b, 0x24,
  0x5c, 0x00,
};

const unsigned char OV2640_YUV422[][2]= 
{
  0xFF, 0x00,
  0x05, 0x00,
  0xDA, 0x10,
  0xD7, 0x03,
  0xDF, 0x00,
  0x33, 0x80,
  0x3C, 0x40,
  0xe1, 0x77,
  0x00, 0x00,
};

const unsigned char OV2640_JPEG[][2]=
{
  0xe0, 0x14,
  0xe1, 0x77,
  0xe5, 0x1f,
  0xd7, 0x03,
  0xda, 0x10,
  0xe0, 0x00,
  0xFF, 0x01,
  0x04, 0x08,
};

/* JPG 160x120 */
const unsigned char OV2640_160x120_JPEG[][2]=
{
  0xff, 0x01,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x4f, 0xca,
  0x50, 0xa8,
  0x5a, 0x23,
  0x6d, 0x00,
  0x39, 0x12,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0x64,
  0xc1, 0x4b,
  0x86, 0x35,
  0x50, 0x92,
  0x51, 0xc8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x57, 0x00,
  0x5a, 0x28,
  0x5b, 0x1e,
  0x5c, 0x00,
  0xe0, 0x00,
};

/* JPG, 0x176x144 */
const unsigned char OV2640_176x144_JPEG[][2]=
{
  0xff, 0x01,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x4f, 0xca,
  0x50, 0xa8,
  0x5a, 0x23,
  0x6d, 0x00,
  0x39, 0x12,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0x64,
  0xc1, 0x4b,
  0x86, 0x35,
  0x50, 0x92,
  0x51, 0xc8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x57, 0x00,
  0x5a, 0x2c,
  0x5b, 0x24,
  0x5c, 0x00,
  0xe0, 0x00,
};

/* JPG 320x240 */
const unsigned char OV2640_320x240_JPEG[][2]=
{
  0xff, 0x01,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x4f, 0xca,
  0x50, 0xa8,
  0x5a, 0x23,
  0x6d, 0x00,
  0x39, 0x12,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0x64,
  0xc1, 0x4b,
  0x86, 0x35,
  0x50, 0x89,
  0x51, 0xc8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x57, 0x00,
  0x5a, 0x50,
  0x5b, 0x3c,
  0x5c, 0x00,
  0xe0, 0x00,
};

/* JPG 352x288 */
const unsigned char OV2640_352x288_JPEG[][2]=
{
  0xff, 0x01,
  0x12, 0x40,
  0x17, 0x11,
  0x18, 0x43,
  0x19, 0x00,
  0x1a, 0x4b,
  0x32, 0x09,
  0x4f, 0xca,
  0x50, 0xa8,
  0x5a, 0x23,
  0x6d, 0x00,
  0x39, 0x12,
  0x35, 0xda,
  0x22, 0x1a,
  0x37, 0xc3,
  0x23, 0x00,
  0x34, 0xc0,
  0x36, 0x1a,
  0x06, 0x88,
  0x07, 0xc0,
  0x0d, 0x87,
  0x0e, 0x41,
  0x4c, 0x00,
  0xff, 0x00,
  0xe0, 0x04,
  0xc0, 0x64,
  0xc1, 0x4b,
  0x86, 0x35,
  0x50, 0x89,
  0x51, 0xc8,
  0x52, 0x96,
  0x53, 0x00,
  0x54, 0x00,
  0x55, 0x00,
  0x57, 0x00,
  0x5a, 0x58,
  0x5b, 0x48,
  0x5c, 0x00,
  0xe0, 0x00,
};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the hardware resources (I2C and GPIO) used to configure 
  *         the OV2640 camera.
  * @param  None
  * @retval None
  */
void OV2640_HW_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  I2C_InitTypeDef  I2C_InitStruct;

  /*** Configures the DCMI GPIOs to interface with the OV2640 camera module ***/
  /* Enable DCMI GPIOs clocks */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOH | 
                         RCC_AHB1Periph_GPIOI, ENABLE);

  /* Connect DCMI pins to AF13 */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_DCMI);

  GPIO_PinAFConfig(GPIOH, GPIO_PinSource8, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOH, GPIO_PinSource9, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOH, GPIO_PinSource10, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOH, GPIO_PinSource11, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOH, GPIO_PinSource12, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOH, GPIO_PinSource14, GPIO_AF_DCMI);

  GPIO_PinAFConfig(GPIOI, GPIO_PinSource5, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOI, GPIO_PinSource6, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOI, GPIO_PinSource7, GPIO_AF_DCMI);
  GPIO_PinAFConfig(GPIOI, GPIO_PinSource4, GPIO_AF_DCMI);
  
  /* DCMI GPIO configuration */
  /* D0..D4(PH9/10/11/12/14), HSYNC(PH8) */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | 
                                GPIO_Pin_12 | GPIO_Pin_14| GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOH, &GPIO_InitStructure);

  /* D5..D7(PI4/6/7), VSYNC(PI5) */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_5;
  GPIO_Init(GPIOI, &GPIO_InitStructure);

  /* PCLK(PA6) */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /****** Configures the I2C1 used for OV2640 camera module configuration *****/
 /* I2C1 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

  /* GPIOB clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Connect I2C1 pins to AF4 */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1);
  
  /* Configure I2C1 GPIOs */  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure I2C1 */
  /* I2C DeInit */ 
  I2C_DeInit(I2C1);
    
  /* Enable the I2C peripheral */
  I2C_Cmd(I2C1, ENABLE);
 
  /* Set the I2C structure parameters */
  I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;
  I2C_InitStruct.I2C_OwnAddress1 = 0xFE;
  I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStruct.I2C_ClockSpeed = 30000;
  
  /* Initialize the I2C peripheral w/ selected parameters */
  I2C_Init(I2C1, &I2C_InitStruct);
}

/**
  * @brief  Resets the OV2640 camera.
  * @param  None
  * @retval None
  */
void OV2640_Reset(void)
{
  OV2640_WriteReg(OV2640_DSP_RA_DLMT, 0x01);
  OV2640_WriteReg(OV2640_SENSOR_COM7, 0x80);
}

/**
  * @brief  Reads the OV2640 Manufacturer identifier.
  * @param  OV2640ID: Pointer to the OV2640 Manufacturer identifier
  * @retval None
  */
void OV2640_ReadID(OV2640_IDTypeDef *OV2640ID)
{
  OV2640_WriteReg(OV2640_DSP_RA_DLMT, 0x01);
  OV2640ID->Manufacturer_ID1 = OV2640_ReadReg(OV2640_SENSOR_MIDH);
  OV2640ID->Manufacturer_ID2 = OV2640_ReadReg(OV2640_SENSOR_MIDL);
  OV2640ID->PIDH = OV2640_ReadReg(OV2640_SENSOR_PIDH);
  OV2640ID->PIDL = OV2640_ReadReg(OV2640_SENSOR_PIDL);
}

/**
  * @brief  Configures DCMI/DMA to capture image from the OV2640 camera.
  * @param  ImageFormat: Image format BMP or JPEG 
  * @param  BMPImageSize: BMP Image size
  * @retval None
  */
void OV2640_Init(ImageFormat_TypeDef ImageFormat)
{
  DCMI_InitTypeDef DCMI_InitStructure;
  DMA_InitTypeDef  DMA_InitStructure;

  /*** Configures the DCMI to interface with the OV2640 camera module ***/
  /* Enable DCMI clock */
  RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_DCMI, ENABLE);

  /* DCMI configuration */ 
  DCMI_InitStructure.DCMI_CaptureMode = DCMI_CaptureMode_Continuous;
  DCMI_InitStructure.DCMI_SynchroMode = DCMI_SynchroMode_Hardware;
  DCMI_InitStructure.DCMI_PCKPolarity = DCMI_PCKPolarity_Rising;
  DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_Low;
  DCMI_InitStructure.DCMI_HSPolarity = DCMI_HSPolarity_Low;
  DCMI_InitStructure.DCMI_CaptureRate = DCMI_CaptureRate_All_Frame;
  DCMI_InitStructure.DCMI_ExtendedDataMode = DCMI_ExtendedDataMode_8b;

  /* Configures the DMA2 to transfer Data from DCMI */
  /* Enable DMA2 clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
  
  /* DMA2 Stream1 Configuration */  
  DMA_DeInit(DMA2_Stream1);

  DMA_InitStructure.DMA_Channel = DMA_Channel_1;  
  DMA_InitStructure.DMA_PeripheralBaseAddr = DCMI_DR_ADDRESS;	
  DMA_InitStructure.DMA_Memory0BaseAddr = FSMC_LCD_ADDRESS;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = 1;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

  switch(ImageFormat)
  {
    case BMP_QQVGA:
    {
      /* DCMI configuration */ 
      DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_High;
      DCMI_Init(&DCMI_InitStructure);

      /* DMA2 IRQ channel Configuration */
      DMA_Init(DMA2_Stream1, &DMA_InitStructure);
      break;
    }
    case BMP_QVGA:
    {
      /* DCMI configuration */
      DCMI_Init(&DCMI_InitStructure);

      /* DMA2 IRQ channel Configuration */
      DMA_Init(DMA2_Stream1, &DMA_InitStructure);
      break;
    }
     default:
    {
      /* DCMI configuration */ 
      DCMI_InitStructure.DCMI_VSPolarity = DCMI_VSPolarity_High;
      DCMI_Init(&DCMI_InitStructure);

      /* DMA2 IRQ channel Configuration */
      DMA_Init(DMA2_Stream1, &DMA_InitStructure);
      break;
    }
  }
}

/**
  * @brief  Configures the OV2640 camera in QQVGA mode.
  * @param  None
  * @retval None
  */
void OV2640_QQVGAConfig(void)
{
  uint32_t i;

  OV2640_Reset();
  Delay(200);

  /* Initialize OV2640 */
  for(i=0; i<(sizeof(OV2640_QQVGA)/2); i++)
  {
    OV2640_WriteReg(OV2640_QQVGA[i][0], OV2640_QQVGA[i][1]);
    Delay(2);
  }
}

/**
  * @brief  Configures the OV2640 camera in QVGA mode.
  * @param  None
  * @retval None
  */
void OV2640_QVGAConfig(void)
{
  uint32_t i;

  OV2640_Reset();
  Delay(200);

  /* Initialize OV2640 */
  for(i=0; i<(sizeof(OV2640_QVGA)/2); i++)
  {
    OV2640_WriteReg(OV2640_QVGA[i][0], OV2640_QVGA[i][1]);
    Delay(2);
  }
}

/**
  * @brief  Configures the OV2640 camera in JPEG mode.
  * @param  JPEGImageSize: JPEG image size
  * @retval None
  */
void OV2640_JPEGConfig(ImageFormat_TypeDef ImageFormat)
{
  uint32_t i;

  OV2640_Reset();
  Delay(200);

  /* Initialize OV2640 */
  for(i=0; i<(sizeof(OV2640_JPEG_INIT)/2); i++)
  {
    OV2640_WriteReg(OV2640_JPEG_INIT[i][0], OV2640_JPEG_INIT[i][1]);
  }

  /* Set to output YUV422 */
  for(i=0; i<(sizeof(OV2640_YUV422)/2); i++)
  {
    OV2640_WriteReg(OV2640_YUV422[i][0], OV2640_YUV422[i][1]);
  }

  OV2640_WriteReg(0xff, 0x01);
  OV2640_WriteReg(0x15, 0x00);

  /* Set to output JPEG */
  for(i=0; i<(sizeof(OV2640_JPEG)/2); i++)
  {
    OV2640_WriteReg(OV2640_JPEG[i][0], OV2640_JPEG[i][1]);
  }

  Delay(100);

  switch(ImageFormat)
  {
    case JPEG_160x120:
    {
      for(i=0; i<(sizeof(OV2640_160x120_JPEG)/2); i++)
      {
        OV2640_WriteReg(OV2640_160x120_JPEG[i][0], OV2640_160x120_JPEG[i][1]);
      }
      break;
    }
    case JPEG_176x144:
    {
      for(i=0; i<(sizeof(OV2640_176x144_JPEG)/2); i++)
      {
        OV2640_WriteReg(OV2640_176x144_JPEG[i][0], OV2640_176x144_JPEG[i][1]);
      } 
      break;
    }
    case JPEG_320x240:
    {
       for(i=0; i<(sizeof(OV2640_320x240_JPEG)/2); i++)
      {
        OV2640_WriteReg(OV2640_320x240_JPEG[i][0], OV2640_320x240_JPEG[i][1]);
      }
      break;
    }
    case JPEG_352x288:
    {
      for(i=0; i<(sizeof(OV2640_352x288_JPEG)/2); i++)
      {
        OV2640_WriteReg(OV2640_352x288_JPEG[i][0], OV2640_352x288_JPEG[i][1]);
      }
      break;
    }
    default:
    {
      for(i=0; i<(sizeof(OV2640_160x120_JPEG)/2); i++)
      {
        OV2640_WriteReg(OV2640_160x120_JPEG[i][0], OV2640_160x120_JPEG[i][1]);
      }
      break;
    }
  }
}

/**
  * @brief  Configures the OV2640 camera brightness.
  * @param  Brightness: Brightness value, where Brightness can be: 
  *         0x40 for Brightness +2,
  *         0x30 for Brightness +1,
  *         0x20 for Brightness 0,
  *         0x10 for Brightness -1,
  *         0x00 for Brightness -2,
  * @retval None
  */
void OV2640_BrightnessConfig(uint8_t Brightness)
{
  OV2640_WriteReg(0xff, 0x00);
  OV2640_WriteReg(0x7c, 0x00);
  OV2640_WriteReg(0x7d, 0x04);
  OV2640_WriteReg(0x7c, 0x09);
  OV2640_WriteReg(0x7d, Brightness);
  OV2640_WriteReg(0x7d, 0x00);
}

/**
  * @brief  Configures the OV2640 camera Black and white mode.
  * @param  BlackWhite: BlackWhite value, where BlackWhite can be: 
  *         0x18 for B&W,
  *         0x40 for Negative,
  *         0x58 for B&W negative,
  *         0x00 for Normal,
  * @retval None
  */
void OV2640_BandWConfig(uint8_t BlackWhite)
{
  OV2640_WriteReg(0xff, 0x00);
  OV2640_WriteReg(0x7c, 0x00);
  OV2640_WriteReg(0x7d, BlackWhite);
  OV2640_WriteReg(0x7c, 0x05);
  OV2640_WriteReg(0x7d, 0x80);
  OV2640_WriteReg(0x7d, 0x80);
}

/**
  * @brief  Configures the OV2640 camera color effects.
  * @param  value1: Color effects value1
  * @param  value2: Color effects value2
  *         where value1 and value2 can be: 
  *         value1 = 0x40, value2 = 0xa6 for Antique,
  *         value1 = 0xa0, value2 = 0x40 for Bluish,
  *         value1 = 0x40, value2 = 0x40 for Greenish,
  *         value1 = 0x40, value2 = 0xc0 for Reddish,
  * @retval None
  */
void OV2640_ColorEffectsConfig(uint8_t value1, uint8_t value2)
{
  OV2640_WriteReg(0xff, 0x00);
  OV2640_WriteReg(0x7c, 0x00);
  OV2640_WriteReg(0x7d, 0x18);
  OV2640_WriteReg(0x7c, 0x05);
  OV2640_WriteReg(0x7d, value1);
  OV2640_WriteReg(0x7d, value2);
}

/**
  * @brief  Configures the OV2640 camera contrast.
  * @param  value1: Contrast value1
  * @param  value2: Contrast value2
  *         where value1 and value2 can be: 
  *         value1 = 0x28, value2 = 0x0c for Contrast +2,
  *         value1 = 0x24, value2 = 0x16 for Contrast +1,
  *         value1 = 0x20, value2 = 0x20 for Contrast 0,
  *         value1 = 0x1c, value2 = 0x2a for Contrast -1,
  *         value1 = 0x18, value2 = 0x34 for Contrast -2,
  * @retval None
  */
void OV2640_ContrastConfig(uint8_t value1, uint8_t value2)
{
  OV2640_WriteReg(0xff, 0x00);
  OV2640_WriteReg(0x7c, 0x00);
  OV2640_WriteReg(0x7d, 0x04);
  OV2640_WriteReg(0x7c, 0x07);
  OV2640_WriteReg(0x7d, 0x20);
  OV2640_WriteReg(0x7d, value1);
  OV2640_WriteReg(0x7d, value2);
  OV2640_WriteReg(0x7d, 0x06);
}

/**
  * @brief  Writes a byte at a specific Camera register
  * @param  Addr: OV2640 register address.
  * @param  Data: Data to be written to the specific register 
  * @retval 0x00 if write operation is OK.
  *       0xFF if timeout condition occurred (device not connected or bus error).
  */
uint8_t OV2640_WriteReg(uint16_t Addr, uint8_t Data)
{
  uint32_t timeout = DCMI_TIMEOUT_MAX;
  
  /* Generate the Start Condition */
  I2C_GenerateSTART(I2C1, ENABLE);

  /* Test on I2C1 EV5 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }
   
  /* Send DCMI selected device slave Address for write */
  I2C_Send7bitAddress(I2C1, OV2640_DEVICE_WRITE_ADDRESS, I2C_Direction_Transmitter);
 
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }
 
  /* Send I2C1 location address LSB */
  I2C_SendData(I2C1, (uint8_t)(Addr));

  /* Test on I2C1 EV8 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }
  
  /* Send Data */
  I2C_SendData(I2C1, Data);

  /* Test on I2C1 EV8 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }  
 
  /* Send I2C1 STOP Condition */
  I2C_GenerateSTOP(I2C1, ENABLE);
  
  /* If operation is OK, return 0 */
  return 0;
}

/**
  * @brief  Reads a byte from a specific Camera register
  * @param  Addr: OV2640 register address.
  * @retval data read from the specific register or 0xFF if timeout condition
  *         occurred. 
  */
uint8_t OV2640_ReadReg(uint16_t Addr)
{
  uint32_t timeout = DCMI_TIMEOUT_MAX;
  uint8_t Data = 0;

  /* Generate the Start Condition */
  I2C_GenerateSTART(I2C1, ENABLE);

  /* Test on I2C1 EV5 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 
  
  /* Send DCMI selected device slave Address for write */
  I2C_Send7bitAddress(I2C1, OV2640_DEVICE_READ_ADDRESS, I2C_Direction_Transmitter);
 
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 

  /* Send I2C1 location address LSB */
  I2C_SendData(I2C1, (uint8_t)(Addr));

  /* Test on I2C1 EV8 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 
  
  /* Clear AF flag if arised */
  I2C1->SR1 |= (uint16_t)0x0400;

  /* Generate the Start Condition */
  I2C_GenerateSTART(I2C1, ENABLE);
  
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  } 
  
  /* Send DCMI selected device slave Address for write */
  I2C_Send7bitAddress(I2C1, OV2640_DEVICE_READ_ADDRESS, I2C_Direction_Receiver);
   
  /* Test on I2C1 EV6 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }  
 
  /* Prepare an NACK for the next data received */
  I2C_AcknowledgeConfig(I2C1, DISABLE);

  /* Test on I2C1 EV7 and clear it */
  timeout = DCMI_TIMEOUT_MAX; /* Initialize timeout value */
  while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED))
  {
    /* If the timeout delay is exceeded, exit with error code */
    if ((timeout--) == 0) return 0xFF;
  }   
    
  /* Prepare Stop after receiving data */
  I2C_GenerateSTOP(I2C1, ENABLE);

  /* Receive the Data */
  Data = I2C_ReceiveData(I2C1);

  /* return the read data */
  return Data;
}

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
