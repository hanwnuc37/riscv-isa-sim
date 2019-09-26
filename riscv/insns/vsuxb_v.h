// vsuxb.v and vsxseg[2-8]b.v
require_vector;
require(P.VU.vsew >= e8);
reg_t vl = P.VU.vl;
reg_t baseAddr = RS1;
reg_t stride = insn.rs2();
reg_t vs3 = insn.rd();
reg_t vlmax = P.VU.vlmax;
VI_DUPLICATE_VREG(stride, vlmax);
for (reg_t i = 0; i < vlmax && vl != 0; ++i) {
  VI_ELEMENT_SKIP(i);
  VI_STRIP(i)

  switch (P.VU.vsew) {
  case e8:
    MMU.store_uint8(baseAddr + index[i],
                    P.VU.elt<uint8_t>(vs3, vreg_inx));
    break;
  case e16:
    MMU.store_uint8(baseAddr + index[i],
                    P.VU.elt<uint16_t>(vs3, vreg_inx));
    break;
  case e32:
    MMU.store_uint8(baseAddr + index[i],
                      P.VU.elt<uint32_t>(vs3, vreg_inx));
    break;
  case e64:
    MMU.store_uint8(baseAddr + index[i],
                    P.VU.elt<uint64_t>(vs3, vreg_inx));
    break;
  }
}
P.VU.vstart = 0;
