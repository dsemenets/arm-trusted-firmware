/*
 * Copyright (c) 2015-2017, Renesas Electronics Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Renesas nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#define RCAR_DDR_VERSION        "rev.0.21"
#define DRAM_CH_CNT		0x04
#define SLICE_CNT		0x04
#define CS_CNT			0x02
/* order : CS0A, CS0B, CS1A, CS1B */
#define CSAB_CNT		(CS_CNT*2)
/* order : CH0A, CH0B, CH1A, CH1B, CH2A, CH2B, CH3A, CH3B */
#define CHAB_CNT		(DRAM_CH_CNT*2)

/* for pll setting */
#define CLK_DIV(a,diva, b,divb) (((a)*(divb))/((b)*(diva)))
#define CLK_MUL(a,diva, b,divb) (((a)*(b))/((diva)*(divb)))
/* for ddr deisity setting */
#define DBMEMCONF_REG(d3,row,bank,col,dw) ((d3)<<30 | ((row)<<24) | ((bank)<<16) | ((col)<<8) | (dw))
#define DBMEMCONF_REGD(density) (DBMEMCONF_REG((density)%2,((density)+1)/2+(29-3-10-2),3,10,2))
#define DBMEMCONF_VAL(ch,cs) (DBMEMCONF_REGD(DBMEMCONF_DENS(ch,cs)))
/* refresh mode */
#define	DBSC_REFINTS			0x0		// 0: Average interval is REFINT. / 1: Average interval is 1/2 REFINT.
/* system registers */
#define	RST_BASE		(0xE6160000U)
#define	RST_MODEMR		(RST_BASE + 0x0060U)
#define	CPG_BASE		(0xE6150000U)
#define	CPG_PLLECR		(CPG_BASE + 0x000D0U)
#define	CPG_CPGWPR		(CPG_BASE + 0x0900U)
#define	CPG_PLL1CR		(CPG_BASE + 0x0028U)
#define	CPG_PLL3CR		(CPG_BASE + 0x00DCU)
#define	CPG_SRCR4		(CPG_BASE + 0x00BCU)
#define	CPG_SRSTCLR4	(CPG_BASE + 0x0950U)
#define CPG_PLLECR_PLL3E_BIT	(1<<3)
#define CPG_PLLECR_PLL3ST_BIT	(1<<11)
/* PLL3 W/A */
#define	CPG_FRQCRB		(CPG_BASE + 0x0004U)
#define	CPG_FRQCRB_KICK_BIT		(1<<31)
#define	CPG_FRQCRD		(CPG_BASE + 0x00E4U)
#define	CPG_MSTPCRM1	(CPG_BASE + 0x0380U)
#define CPG_MSTPCRM1_ZB3ST_BIT   (1<<11)
/* chip_id and calibration code */
#define LIFEC_CHIPID(x)		(0xE6110040U+(x)*4)
#define LIFEC_TERMCODE		0xE61100BCU
/* Product Register */
#define PRR			(0xFFF00044U)
#define PRR_PRODUCT_MASK	(0x00007F00U)
#define PRR_CUT_MASK		(0x000000FFU)
#define PRR_PRODUCT_H3		(0x00004F00U)           /* R-Car H3 */
#define PRR_PRODUCT_M3		(0x00005200U)           /* R-Car M3 */
#define PRR_PRODUCT_10		(0x00U)
#define PRR_PRODUCT_11		(0x01U)
/* DBSC registers */
#define DBSC_DBSYSCONF1		0xE6790004U
#define DBSC_DBPHYCONF0		0xE6790010U
#define DBSC_DBKIND		0xE6790020U

#define DBSC_DBMEMCONF(ch,cs)	(0xE6790030U+0x10U*ch+0x4U*cs)
#define DBSC_DBMEMCONF_0_0	0xE6790030U
#define DBSC_DBMEMCONF_0_1	0xE6790034U
#define DBSC_DBMEMCONF_0_2	0xE6790038U
#define DBSC_DBMEMCONF_0_3	0xE679003CU
#define DBSC_DBMEMCONF_1_2	0xE6790048U
#define DBSC_DBMEMCONF_1_3	0xE679004CU
#define DBSC_DBMEMCONF_1_0	0xE6790040U
#define DBSC_DBMEMCONF_1_1	0xE6790044U
#define DBSC_DBMEMCONF_2_0	0xE6790050U
#define DBSC_DBMEMCONF_2_1	0xE6790054U
#define DBSC_DBMEMCONF_2_2	0xE6790058U
#define DBSC_DBMEMCONF_2_3	0xE679005CU
#define DBSC_DBMEMCONF_3_0	0xE6790060U
#define DBSC_DBMEMCONF_3_1	0xE6790064U
#define DBSC_DBMEMCONF_3_2	0xE6790068U
#define DBSC_DBMEMCONF_3_3	0xE679006CU

#define DBSC_DBSTATE0		0xE6790108U

#define DBSC_DBACEN		0xE6790200U
#define DBSC_DBRFEN		0xE6790204U
#define DBSC_DBCMD		0xE6790208U
#define DBSC_DBWAIT		0xE6790210U
#define DBSC_DBSYSCTRL0		0xE6790280U

#define DBSC_DBTR(x)		(0xE6790300U+4*x)
#define DBSC_DBTR0		0xE6790300U
#define DBSC_DBTR1		0xE6790304U
#define DBSC_DBTR3		0xE679030CU
#define DBSC_DBTR4		0xE6790310U
#define DBSC_DBTR5		0xE6790314U
#define DBSC_DBTR6		0xE6790318U
#define DBSC_DBTR7		0xE679031CU
#define DBSC_DBTR8		0xE6790320U
#define DBSC_DBTR9		0xE6790324U
#define DBSC_DBTR10		0xE6790328U
#define DBSC_DBTR11		0xE679032CU
#define DBSC_DBTR12		0xE6790330U
#define DBSC_DBTR13		0xE6790334U
#define DBSC_DBTR14		0xE6790338U
#define DBSC_DBTR15		0xE679033CU
#define DBSC_DBTR16		0xE6790340U
#define DBSC_DBTR17		0xE6790344U
#define DBSC_DBTR18		0xE6790348U
#define DBSC_DBTR19		0xE679034CU
#define DBSC_DBTR20		0xE6790350U
#define DBSC_DBTR21		0xE6790354U
#define DBSC_DBTR22		0xE6790358U
#define DBSC_DBTR23		0xE679035CU
#define DBSC_DBTR24		0xE6790360U
#define DBSC_DBTR25		0xE6790364U

#define DBSC_DBBL		0xE6790400U

#define DBSC_DBRFCNF1		0xE6790414U
#define DBSC_DBRFCNF2		0xE6790418U

#define DBSC_DBCALCNF		0xE6790424U

#define DBSC_DBRNK(x)		(0xE6790430U+0x4*(x))
#define DBSC_DBRNK2		0xE6790438U
#define DBSC_DBRNK3		0xE679043CU
#define DBSC_DBRNK4		0xE6790440U
#define DBSC_DBRNK5		0xE6790444U

#define DBSC_DBADJ0		0xE6790500U
#define DBSC_DBADJ2		0xE6790508U
#define DBSC_DBDBICNT		0xE6790518U

#define DBSC_DBDFIPMSTRCNF	0xE6790520U

#define DBSC_DBPDLK(ch)		(0xE6790620U+0x40U*(ch))
#define DBSC_DBPDLK_0		0xE6790620U
#define DBSC_DBPDLK_1		0xE6790660U
#define DBSC_DBPDLK_2		0xE67906a0U
#define DBSC_DBPDLK_3		0xE67906e0U

#define DBSC_INITCOMP(ch)	(0xE6790600U+0x40U*(ch))
#define DBSC_INITCOMP_0		0xE6790600U
#define DBSC_INITCOMP_1		0xE6790640U
#define DBSC_INITCOMP_2		0xE6790680U
#define DBSC_INITCOMP_3		0xE67906C0U

#define DBSC_DBDFICNT(ch)	(0xE6790604U+0x40U*(ch))
#define DBSC_DBDFICNT_0		0xE6790604U
#define DBSC_DBDFICNT_1		0xE6790644U
#define DBSC_DBDFICNT_2		0xE6790684U
#define DBSC_DBDFICNT_3		0xE67906C4U

#define DBSC_DBPDCNT0(ch)	(0xE6790610U+0x40U*(ch))
#define DBSC_DBPDCNT0_0		0xE6790610U
#define DBSC_DBPDCNT0_1		0xE6790650U
#define DBSC_DBPDCNT0_2		0xE6790690U
#define DBSC_DBPDCNT0_3		0xE67906D0U

#define DBSC_DBPDCNT3(ch)	(0xE679061CU+0x40U*(ch))
#define DBSC_DBPDCNT3_0		0xE679061CU
#define DBSC_DBPDCNT3_1		0xE679065CU
#define DBSC_DBPDCNT3_2		0xE679069CU
#define DBSC_DBPDCNT3_3		0xE67906DCU

#define DBSC_DBPDRGA(ch)	(0xE6790624U+0x40U*(ch))
#define DBSC_DBPDRGD(ch)	(0xE6790628U+0x40U*(ch))
#define DBSC_DBPDRGA_0		0xE6790624U
#define DBSC_DBPDRGD_0		0xE6790628U
#define DBSC_DBPDRGA_1		0xE6790664U
#define DBSC_DBPDRGD_1		0xE6790668U
#define DBSC_DBPDRGA_2		0xE67906A4U
#define DBSC_DBPDRGD_2		0xE67906A8U
#define DBSC_DBPDRGA_3		0xE67906E4U
#define DBSC_DBPDRGD_3		0xE67906E8U

#define DBSC_DBPDSTAT(ch)	(0xE6790630U+0x40U*(ch))
#define DBSC_DBPDSTAT_0		0xE6790630U
#define DBSC_DBPDSTAT_1		0xE6790670U
#define DBSC_DBPDSTAT_2		0xE67906B0U
#define DBSC_DBPDSTAT_3		0xE67906F0U

#define DBSC_DBBUS0CNF0		0xE6790800U
#define DBSC_DBBUS0CNF1		0xE6790804U

#define DBSC_DBCAM0CNF0		0xE6790900U
#define DBSC_DBCAM0CNF1		0xE6790904U
#define DBSC_DBCAM0CNF2		0xE6790908U
#define DBSC_DBCAM0CNF3		0xE679090CU
#define DBSC_DBBCAMSWAP		0xE67909F0U
#define DBSC_DBBCAMDIS		0xE67909FCU
#define DBSC_DBSCHCNT0		0xE6791000U
#define DBSC_DBSCHCNT1		0xE6791004U
#define DBSC_DBSCHSZ0		0xE6791010U
#define DBSC_DBSCHRW0		0xE6791020U
#define DBSC_DBSCHRW1		0xE6791024U

#define DBSC_DBSCHQOS_0(x)	(0xE6791030U+0x10U*(x))
#define DBSC_DBSCHQOS_1(x)	(0xE6791034U+0x10U*(x))
#define DBSC_DBSCHQOS_2(x)	(0xE6791038U+0x10U*(x))
#define DBSC_DBSCHQOS_3(x)	(0xE679103CU+0x10U*(x))

#define DBSC_DBSCTR0		0xE6791700U
#define DBSC_DBSCTR1		0xE6791708U
#define DBSC_DBSCHRW2		0xE679170CU

#define DBSC_SCFCTST01(x)	(0xE6791700U+8*(x))
#define DBSC_SCFCTST0		0xE6791700U
#define DBSC_SCFCTST1		0xE6791708U
#define DBSC_SCFCTST2		0xE679170CU

#define DBSC_DBMRRDR_0		0xE6791800U
#define DBSC_DBMRRDR_1		0xE6791804U
#define DBSC_DBMRRDR_2		0xE6791808U
#define DBSC_DBMRRDR_3		0xE679180CU
#define DBSC_DBMRRDR_4		0xE679180CU
#define DBSC_DBMRRDR_5		0xE679180CU
#define DBSC_DBMRRDR_6		0xE679180CU
#define DBSC_DBMRRDR_7		0xE679180CU
#define DBSC_DBMRRDR(chab)	(0xE6791800U+0x4U*(chab))

#define DBSC_DBMEMSWAPCONF0	0xE6792000U

#define DBSC_DBMONCONF4		0xE6793010U

#define DBSC_PLL_LOCK(ch)	(0xE6794054U+0x100U*(ch))
#define DBSC_PLL_LOCK_0		0xE6794054U
#define DBSC_PLL_LOCK_1		0xE6794154U
#define DBSC_PLL_LOCK_2		0xE6794254U
#define DBSC_PLL_LOCK_3		0xE6794354U

#define DBSC_DBTSTCONF1		0xE6794804U
	
#define DBSC_DBPDCNT2(ch)	(0xE6790618U+0x40U*(ch))
#define DBSC_FREQ_CHG_ACK_0	0xE6790618U
#define DBSC_FREQ_CHG_ACK_1	0xE6790658U
#define DBSC_FREQ_CHG_ACK_2	0xE6790698U
#define DBSC_FREQ_CHG_ACK_3	0xE67906D8U

#define DBSC_DBPDCNT1(ch)	(0xE6790614U+0x40U*(ch))
#define DBSC_DFI_FREQ_0		0xE6790614U
#define DBSC_DFI_FREQ_1		0xE6790654U
#define DBSC_DFI_FREQ_2		0xE6790694U
#define DBSC_DFI_FREQ_3		0xE67906D4U
/* STAT registers */
#define MSTATQ_STATQC		0xE67E8008U
#define MSTATQ_WTENABLE		0xE67E8030U
#define MSTATQ_WTREFRESH	0xE67E8034U
#define MSTATQ_WTSETTING0	0xE67E8038U
#define MSTATQ_WTSETTING1	0xE67E803CU
