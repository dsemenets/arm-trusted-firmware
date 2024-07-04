/*
 * Copyright 2024 EPAM Systems
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>

#include <common/debug.h>
#include <drivers/scmi.h>
#include <lib/utils_def.h>
#include <platform_def.h>

size_t plat_scmi_rstd_count(unsigned int agent_id __unused)
{
	WARN("%s, agent_id = %d\n", __func__,
			agent_id);
	return 1U;
}

const char *plat_scmi_rstd_get_name(unsigned int agent_id __unused,
				  unsigned int scmi_id __unused)
{
	WARN("%s, agent_id = %d scmi_id = %d\n", __func__,
				agent_id, scmi_id);
	return SCMI_SUCCESS;
}

int32_t plat_scmi_rstd_autonomous(unsigned int agent_id __unused,
				unsigned int scmi_id __unused,
				unsigned int state __unused)
{
	WARN("%s, agent_id = %d scmi_id = %d state = %d\n", __func__,
				agent_id, scmi_id, state);
	return SCMI_SUCCESS;
}

int32_t plat_scmi_rstd_set_state(unsigned int agent_id __unused,
			       unsigned int scmi_id __unused,
			       bool assert_not_deassert __unused)
{
	WARN("%s, agent_id = %d scmi_id = %d assert = %d\n", __func__,
			agent_id, scmi_id, assert_not_deassert);
	return SCMI_SUCCESS;
}
