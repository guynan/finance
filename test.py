

import finance as f


def main():

    print(f.fv_annuity(1000, 0.1, 4));
    print(f.pv_annuity(1000, 0.1, 4));
    print(f.annuity_factor(0.1, 4));


main();
