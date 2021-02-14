#include "Card.hpp"

int main(int argc, char** argv)
{
    Card* KingKrush = new Card("King Krush", 8, 8, 8);
    KingKrush->display();

    Card* KhartutDefender = new Card("Khartut Defender", 6, 3, 4);
    KhartutDefender->display();

    Card* spiritJailer = new Card("Spirit Jailer", 1, 1, 3);
    spiritJailer->display();

    Card* armorVendor = new Card("Armor Vendor", 1, 1, 3);
    armorVendor->display();

    Card* JandiceBarov = new Card("Jandice Barov", 5,2,1);
    JandiceBarov->display();


}