/*
 * Copyright 2024 EPAM Systems
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLAT_RPI_RPI5_INCLUDE_RPI5_SMC_H_
#define PLAT_RPI_RPI5_INCLUDE_RPI5_SMC_H_

#include <lib/smccc.h>

/*
 * Process scmi message pending in the SCMI message
 * shared memory buffer.
 */
#define RPI5_SIP_SMC_SCMI 0x82000002

/*
 * Error codes for SMC calls
 */
#define RPI5_SMC_OK			SMC_OK
#define RPI5_SMC_NOT_SUPPORTED		SMC_UNK

#endif /* PLAT_RPI_RPI5_INCLUDE_RPI5_SMC_H_ */
