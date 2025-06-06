/*
 * An dfd_psu_driver driver for dfd psu function
 *
 * Copyright (C) 2024 Micas Networks Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <linux/module.h>
#include <linux/slab.h>

#include "./include/dfd_module.h"
#include "./include/dfd_cfg.h"
#include "./include/dfd_cfg_adapter.h"
#include "./include/dfd_cfg_info.h"
#include "../dev_sysfs/include/sysfs_common.h"

#define PSU_SIZE                         (256)

typedef enum dfd_psu_status_e {
    DFD_PSU_PRESENT_STATUS  = 0,
    DFD_PSU_OUTPUT_STATUS   = 1,
    DFD_PSU_ALERT_STATUS    = 2,
} dfd_psu_status_t;

int g_dfd_psu_dbg_level = 0;
module_param(g_dfd_psu_dbg_level, int, S_IRUGO | S_IWUSR);

int dfd_get_psu_present_status(unsigned int psu_index)
{
    int ret, present_key, present_status;

    present_key = DFD_CFG_KEY(DFD_CFG_ITEM_PSU_STATUS, psu_index, DFD_PSU_PRESENT_STATUS);
    ret = dfd_info_get_int(present_key, &present_status, NULL);
    if (ret < 0) {
        DFD_PSU_DEBUG(DBG_ERROR, "dfd_get_psu_present_status error. psu_index:%d, ret:%d\n",
            psu_index, ret);
        return ret;
    }

    DFD_PSU_DEBUG(DBG_VERBOSE, "dfd_get_psu_present_status success. psu_index:%d, status:%d\n",
        psu_index, present_status);
    return present_status;
}

int dfd_get_psu_output_status(unsigned int psu_index)
{
    int ret, output_key, output_status;

    output_key = DFD_CFG_KEY(DFD_CFG_ITEM_PSU_STATUS, psu_index, DFD_PSU_OUTPUT_STATUS);
    ret = dfd_info_get_int(output_key, &output_status, NULL);
    if (ret < 0) {
        DFD_PSU_DEBUG(DBG_ERROR, "dfd_get_psu_output_status error. psu_index:%d, ret:%d\n",
            psu_index, ret);
        return ret;
    }

    DFD_PSU_DEBUG(DBG_VERBOSE, "dfd_get_psu_output_status success. psu_index:%d, status:%d\n",
        psu_index, output_status);
    return output_status;
}

int dfd_get_psu_alert_status(unsigned int psu_index)
{
    int ret, alert_key, alert_status;

    alert_key = DFD_CFG_KEY(DFD_CFG_ITEM_PSU_STATUS, psu_index, DFD_PSU_ALERT_STATUS);
    ret = dfd_info_get_int(alert_key, &alert_status, NULL);
    if (ret < 0) {
        DFD_PSU_DEBUG(DBG_ERROR, "dfd_get_psu_alert_status error. psu_index:%d, ret:%d\n",
            psu_index, ret);
        return ret;
    }

    DFD_PSU_DEBUG(DBG_VERBOSE, "dfd_get_psu_alert_status success. psu_index:%d, status:%d\n",
        psu_index, alert_status);
    return alert_status;
}
