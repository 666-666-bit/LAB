// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard.h"
#include "VDevelopmentBoard__Syms.h"

//==========

void VDevelopmentBoard::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDevelopmentBoard::eval\n"); );
    VDevelopmentBoard__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DevelopmentBoard.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDevelopmentBoard::_eval_initial_loop(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DevelopmentBoard.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__1\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*18:0*/ __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms;
    // Body
    __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms;
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__key_reg) 
             != (IData)(vlTOPp->B2))) {
            __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms = 0xaU;
        } else {
            if ((0U < vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms)) {
                __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms 
                    = (0x7ffffU & (vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms 
                                   - (IData)(1U)));
            }
        }
    } else {
        __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms = 0U;
    }
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__key_flag 
        = ((IData)(vlTOPp->reset) & ((1U == vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms) 
                                     & (~ (IData)(vlTOPp->B2))));
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk)));
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms 
        = __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__cnt_20ms;
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_key_debounce__DOT__key_reg 
        = (1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->B2)));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__3(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__3\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h;
    // Body
    __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h;
    if (vlTOPp->reset) {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_data 
            = ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__cur_state))
                ? ((0x50U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                    ? 0xf800U : ((0xa0U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                                  ? 0xfd20U : ((0xf0U 
                                                > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                                                ? 0xffe0U
                                                : (
                                                   (0x140U 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                                                    ? 0x7e0U
                                                    : 
                                                   ((0x190U 
                                                     > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                                                     ? 0x7ffU
                                                     : 
                                                    ((0x1e0U 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                                                      ? 0x1fU
                                                      : 
                                                     ((0x230U 
                                                       > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))
                                                       ? 0U
                                                       : 0xffffU)))))))
                : ((1U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__cur_state))
                    ? ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                         & (0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                        & (0xcfU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                        ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                     - (IData)(0xd0U)))
                            ? ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                         - (IData)(0xd0U)))
                                ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0xc3U 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U)
                                    : ((1U & (0xc3U 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U))
                                : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0xc3U 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U)
                                    : ((1U & (0xc3U 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U)))
                            : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                         - (IData)(0xd0U)))
                                ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0xdbU 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U)
                                    : ((1U & (0xffU 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U))
                                : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0xe7U 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U)
                                    : ((1U & (0xc3U 
                                              >> (7U 
                                                  & ((IData)(7U) 
                                                     - 
                                                     (0x7fU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                          - (IData)(0x90U)) 
                                                         >> 3U))))))
                                        ? 0xffffU : 0U))))
                        : ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                             & (0xf0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                            & (0x12fU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                            ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                         - (IData)(0xd0U)))
                                ? ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                    ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0x3cU 
                                                  >> 
                                                  (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                            ? 0xffffU
                                            : 0U) : 
                                       ((1U & (0x7eU 
                                               >> (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                         ? 0xffffU : 0U))
                                    : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0xc3U 
                                                  >> 
                                                  (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                            ? 0xffffU
                                            : 0U) : 
                                       ((1U & (0xc3U 
                                               >> (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                         ? 0xffffU : 0U)))
                                : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                    ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0xc3U 
                                                  >> 
                                                  (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                            ? 0xffffU
                                            : 0U) : 
                                       ((1U & (0xc3U 
                                               >> (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                         ? 0xffffU : 0U))
                                    : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0xc3U 
                                                  >> 
                                                  (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                            ? 0xffffU
                                            : 0U) : 
                                       ((1U & (0xc3U 
                                               >> (7U 
                                                   & ((IData)(7U) 
                                                      - 
                                                      (0x7fU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                           - (IData)(0xf0U)) 
                                                          >> 3U))))))
                                         ? 0xffffU : 0U))))
                            : ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                                 & (0x150U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                                & (0x18fU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                                ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                    ? ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                 - (IData)(0xd0U)))
                                        ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0x7eU 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U)
                                            : ((1U 
                                                & (0xc3U 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U))
                                        : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0xc3U 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U)
                                            : ((1U 
                                                & (6U 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U)))
                                    : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                 - (IData)(0xd0U)))
                                        ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0x7cU 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U)
                                            : ((1U 
                                                & (0xc0U 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U))
                                        : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0xc3U 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U)
                                            : ((1U 
                                                & (0x7eU 
                                                   >> 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - 
                                                       (0x7fU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                            - (IData)(0x150U)) 
                                                           >> 3U))))))
                                                ? 0xffffU
                                                : 0U))))
                                : ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                                     & (0x1b0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                                    & (0x1efU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                                    ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                 - (IData)(0xd0U)))
                                        ? ((0x10U & 
                                            ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                            ? ((8U 
                                                & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                   - (IData)(0xd0U)))
                                                ? (
                                                   (1U 
                                                    & (0x18U 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (0x18U 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U))
                                            : ((8U 
                                                & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                   - (IData)(0xd0U)))
                                                ? (
                                                   (1U 
                                                    & (0x18U 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (0x18U 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U)))
                                        : ((0x10U & 
                                            ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                            ? ((8U 
                                                & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                   - (IData)(0xd0U)))
                                                ? (
                                                   (1U 
                                                    & (0x18U 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (0x18U 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U))
                                            : ((8U 
                                                & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                   - (IData)(0xd0U)))
                                                ? (
                                                   (1U 
                                                    & (0xffU 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (0xffU 
                                                       >> 
                                                       (7U 
                                                        & ((IData)(7U) 
                                                           - 
                                                           (0x7fU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                - (IData)(0x1b0U)) 
                                                               >> 3U))))))
                                                    ? 0xffffU
                                                    : 0U))))
                                    : 0U)))) : ((2U 
                                                 == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__cur_state))
                                                 ? 
                                                ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                                                   & (0xb8U 
                                                      <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                                                  & (0xf7U 
                                                     >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                                                  ? 
                                                 ((0x20U 
                                                   & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                      - (IData)(0xd0U)))
                                                   ? 
                                                  ((0x10U 
                                                    & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                       - (IData)(0xd0U)))
                                                    ? 
                                                   ((8U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((1U 
                                                      & (0xffU 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U)
                                                     : 
                                                    ((1U 
                                                      & (0xc0U 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U))
                                                    : 
                                                   ((8U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((1U 
                                                      & (0xc0U 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U)
                                                     : 
                                                    ((1U 
                                                      & (0xc0U 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U)))
                                                   : 
                                                  ((0x10U 
                                                    & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                       - (IData)(0xd0U)))
                                                    ? 
                                                   ((8U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((1U 
                                                      & (0xfeU 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U)
                                                     : 
                                                    ((1U 
                                                      & (0xc0U 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U))
                                                    : 
                                                   ((8U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((1U 
                                                      & (0xc0U 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U)
                                                     : 
                                                    ((1U 
                                                      & (0xffU 
                                                         >> 
                                                         (7U 
                                                          & ((IData)(7U) 
                                                             - 
                                                             (0x7fU 
                                                              & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                  - (IData)(0xb8U)) 
                                                                 >> 3U))))))
                                                      ? 0xffffU
                                                      : 0U))))
                                                  : 
                                                 ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                                                    & (0x120U 
                                                       <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                                                   & (0x15fU 
                                                      >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                                                   ? 
                                                  ((0x20U 
                                                    & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                       - (IData)(0xd0U)))
                                                    ? 
                                                   ((0x10U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((8U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((1U 
                                                       & (0xc3U 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U)
                                                      : 
                                                     ((1U 
                                                       & (0xc3U 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U))
                                                     : 
                                                    ((8U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((1U 
                                                       & (0xc7U 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U)
                                                      : 
                                                     ((1U 
                                                       & (0xcfU 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U)))
                                                    : 
                                                   ((0x10U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((8U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((1U 
                                                       & (0xdbU 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U)
                                                      : 
                                                     ((1U 
                                                       & (0xf3U 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U))
                                                     : 
                                                    ((8U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((1U 
                                                       & (0xe3U 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U)
                                                      : 
                                                     ((1U 
                                                       & (0xc3U 
                                                          >> 
                                                          (7U 
                                                           & ((IData)(7U) 
                                                              - 
                                                              (0x7fU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                   - (IData)(0x120U)) 
                                                                  >> 3U))))))
                                                       ? 0xffffU
                                                       : 0U))))
                                                   : 
                                                  ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range) 
                                                     & (0x188U 
                                                        <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
                                                    & (0x1c7U 
                                                       >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))
                                                    ? 
                                                   ((0x20U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((0x10U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((8U 
                                                       & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                          - (IData)(0xd0U)))
                                                       ? 
                                                      ((1U 
                                                        & (0xfcU 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (0xc6U 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U))
                                                      : 
                                                     ((8U 
                                                       & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                          - (IData)(0xd0U)))
                                                       ? 
                                                      ((1U 
                                                        & (0xc3U 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (0xc3U 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U)))
                                                     : 
                                                    ((0x10U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((8U 
                                                       & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                          - (IData)(0xd0U)))
                                                       ? 
                                                      ((1U 
                                                        & (0xc3U 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (0xc3U 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U))
                                                      : 
                                                     ((8U 
                                                       & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                                                          - (IData)(0xd0U)))
                                                       ? 
                                                      ((1U 
                                                        & (0xc6U 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        & (0xfcU 
                                                           >> 
                                                           (7U 
                                                            & ((IData)(7U) 
                                                               - 
                                                               (0x7fU 
                                                                & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                                                    - (IData)(0x188U)) 
                                                                   >> 3U))))))
                                                        ? 0xffffU
                                                        : 0U))))
                                                    : 0U)))
                                                 : 0U)));
        __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h 
            = ((0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h))
                ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h))));
    } else {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_data = 0U;
        __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h = 0U;
    }
    if (vlTOPp->reset) {
        if ((0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h))) {
            vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v 
                = ((0x20cU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v))
                    ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v))));
        }
    } else {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v = 0U;
    }
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h 
        = __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h;
    vlTOPp->h_sync = (0x60U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h));
    vlTOPp->v_sync = (2U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v));
    vlTOPp->rgb = (((((0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h)) 
                      & (0x310U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h))) 
                     & (0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v))) 
                    & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v)))
                    ? (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_data)
                    : 0U);
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__pix_data_req 
        = ((((0x8fU <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h)) 
             & (0x30fU > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h))) 
            & (0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v))) 
           & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v)));
    if (vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__pix_data_req) {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x 
            = (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_h) 
                         - (IData)(0x8fU)));
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y 
            = (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_ctrl__DOT__cnt_v) 
                         - (IData)(0x23U)));
    } else {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x = 0U;
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y = 0U;
    }
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_vga_pic__DOT__in_y_range 
        = ((0xd0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y)) 
           & (0x10fU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y)));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__4(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__4\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__cur_state 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_screen_fsm__DOT__next_state)
            : 0U);
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__key_flag) 
                             << 2U) | (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__cur_state));
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__u_screen_fsm__DOT__next_state 
        = vlTOPp->__Vtable1_DevelopmentBoard__DOT__vga_top_inst__DOT__u_screen_fsm__DOT__next_state
        [vlTOPp->__Vtableidx1];
}

void VDevelopmentBoard::_eval(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
    vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request_1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request_1\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk))) VL_DBG_MSGF("        CHANGE: /home/hjp/桌面/lab4_vga/RTL/vga_top.v:11: DevelopmentBoard.vga_top_inst.vga_clk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
    return __req;
}

#ifdef VL_DEBUG
void VDevelopmentBoard::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((B2 & 0xfeU))) {
        Verilated::overWidthError("B2");}
    if (VL_UNLIKELY((B3 & 0xfeU))) {
        Verilated::overWidthError("B3");}
    if (VL_UNLIKELY((B4 & 0xfeU))) {
        Verilated::overWidthError("B4");}
    if (VL_UNLIKELY((B5 & 0xfeU))) {
        Verilated::overWidthError("B5");}
}
#endif  // VL_DEBUG
