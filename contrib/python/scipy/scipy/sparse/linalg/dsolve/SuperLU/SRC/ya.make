LIBRARY()

NO_COMPILER_WARNINGS()



IF (OS_WINDOWS)
    CFLAGS(-DNO_TIMER=1)
ENDIF()

PEERDIR(
    contrib/libs/libf2c
)

CFLAGS(
    -Dc_sqrt=SuperLU_c_sqrt
    -Dc_exp=SuperLU_c_exp
)

SRCS(
    ccolumn_bmod.c
    ccolumn_dfs.c
    ccopy_to_ucol.c
    cdiagonal.c
    cgscon.c
    cgsequ.c
    cgsisx.c
    cgsitrf.c
    cgsrfs.c
    cgssv.c
    cgssvx.c
    cgstrf.c
    cgstrs.c
    clacon2.c
    clangs.c
    claqgs.c
    cldperm.c
    cmemory.c
    cmyblas2.c
    colamd.c
    cpanel_bmod.c
    cpanel_dfs.c
    cpivotgrowth.c
    cpivotL.c
    cpruneL.c
    creadhb.c
    creadrb.c
    creadtriple.c
    csnode_bmod.c
    csnode_dfs.c
    csp_blas2.c
    csp_blas3.c
    cutil.c
    dcolumn_bmod.c
    dcolumn_dfs.c
    dcomplex.c
    dcopy_to_ucol.c
    ddiagonal.c
    dgscon.c
    dgsequ.c
    dgsisx.c
    dgsitrf.c
    dgsrfs.c
    dgssv.c
    dgssvx.c
    dgstrf.c
    dgstrs.c
    dlacon2.c
    dlangs.c
    dlaqgs.c
    dldperm.c
    dmach.c
    dmemory.c
    dmyblas2.c
    dpanel_bmod.c
    dpanel_dfs.c
    dpivotgrowth.c
    dpivotL.c
    dpruneL.c
    dreadhb.c
    dreadrb.c
    dreadtriple.c
    dsnode_bmod.c
    dsnode_dfs.c
    dsp_blas2.c
    dsp_blas3.c
    dutil.c
    dzsum1.c
    get_perm_c.c
    heap_relax_snode.c
    icmax1.c
    ilu_ccolumn_dfs.c
    ilu_ccopy_to_ucol.c
    ilu_cdrop_row.c
    ilu_cpanel_dfs.c
    ilu_cpivotL.c
    ilu_csnode_dfs.c
    ilu_dcolumn_dfs.c
    ilu_dcopy_to_ucol.c
    ilu_ddrop_row.c
    ilu_dpanel_dfs.c
    ilu_dpivotL.c
    ilu_dsnode_dfs.c
    ilu_heap_relax_snode.c
    ilu_relax_snode.c
    ilu_scolumn_dfs.c
    ilu_scopy_to_ucol.c
    ilu_sdrop_row.c
    ilu_spanel_dfs.c
    ilu_spivotL.c
    ilu_ssnode_dfs.c
    ilu_zcolumn_dfs.c
    ilu_zcopy_to_ucol.c
    ilu_zdrop_row.c
    ilu_zpanel_dfs.c
    ilu_zpivotL.c
    ilu_zsnode_dfs.c
    izmax1.c
    mark_relax.c
    memory.c
    mmd.c
    qselect.c
    relax_snode.c
    scolumn_bmod.c
    scolumn_dfs.c
    scomplex.c
    scopy_to_ucol.c
    scsum1.c
    sdiagonal.c
    sgscon.c
    sgsequ.c
    sgsisx.c
    sgsitrf.c
    sgsrfs.c
    sgssv.c
    sgssvx.c
    sgstrf.c
    sgstrs.c
    slacon2.c
    slangs.c
    slaqgs.c
    sldperm.c
    smach.c
    smemory.c
    smyblas2.c
    spanel_bmod.c
    spanel_dfs.c
    sp_coletree.c
    sp_ienv.c
    spivotgrowth.c
    spivotL.c
    sp_preorder.c
    spruneL.c
    sreadhb.c
    sreadrb.c
    sreadtriple.c
    ssnode_bmod.c
    ssnode_dfs.c
    ssp_blas2.c
    ssp_blas3.c
    superlu_timer.c
    sutil.c
    util.c
    zcolumn_bmod.c
    zcolumn_dfs.c
    zcopy_to_ucol.c
    zdiagonal.c
    zgscon.c
    zgsequ.c
    zgsisx.c
    zgsitrf.c
    zgsrfs.c
    zgssv.c
    zgssvx.c
    zgstrf.c
    zgstrs.c
    zlacon2.c
    zlangs.c
    zlaqgs.c
    zldperm.c
    zmemory.c
    zmyblas2.c
    zpanel_bmod.c
    zpanel_dfs.c
    zpivotgrowth.c
    zpivotL.c
    zpruneL.c
    zreadhb.c
    zreadrb.c
    zreadtriple.c
    zsnode_bmod.c
    zsnode_dfs.c
    zsp_blas2.c
    zsp_blas3.c
    zutil.c
)

END()
