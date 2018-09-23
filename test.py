

import finance as f


def main():

    print(f.fv_annuity(1000, 0.1, 4));
    print(f.pv_annuity(1000, 0.1, 4));
    print(f.annuity_factor(0.1, 4));


    print(f.bond_price(60.0, 0.07, 1000, 40));

    print(f.bond_price(100.0, 0.12, 1000, 5));


    print(f.yield_to_maturity(50.0, 898.90, 1000, 16));

    print(f.coupon_rate(1053.46, 0.06, 1000, 3));

    print(f.bond_price(85.0 / 2, 0.0523/2, 1000, 6 * 2));
    print(f.real_return(0.0381, 0.02));

main();
