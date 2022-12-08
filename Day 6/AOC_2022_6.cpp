// AOC_2022_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Datastream_Buffer.h"
#include <map>
#include <utility>

void to_empty_bool(std::pair<bool, int> bool_to_false[26]) {

    for (int i = 0; i < 26; i++) { bool_to_false[i].first = 0; bool_to_false[i].second = 0; }

    return;

}

int n_marker(const Datastream_Buffer datastream_buffer, const int characters_before_buffer) {

    std::pair <bool, int> char_is_encountered [26];

    to_empty_bool(char_is_encountered);

    size_t buffer_size = datastream_buffer.get_size();

    int marker = 0;
    int i = 0;

    while (i < buffer_size && marker < characters_before_buffer) {

        if (char_is_encountered[datastream_buffer[i] - 'a'].first == 0) {

            marker++;
            char_is_encountered[datastream_buffer[i] - 'a'].first = 1;
            char_is_encountered[datastream_buffer[i] - 'a'].second = i;

        }

        else {

            i = char_is_encountered[datastream_buffer[i] - 'a'].second + 1;
            marker = 1;
            to_empty_bool(char_is_encountered);
            char_is_encountered[datastream_buffer[i] - 'a'].first = 1;
            char_is_encountered[datastream_buffer[i] - 'a'].second = i;

        }

        i++;
    }

    return i;

}

int main()
{
    Datastream_Buffer stream("mgwwjddqzqdqsstctjjsdjsdsrsfsmfsfwwltwlwhwnhhlffzddgffwlffbsfshfshhgvvdrrltlzlnzznrrnrsnnhgnnfjnnvpnnbjjnwwrcwrrhlhvlhhmzmqzqrqtqmqpmpwwmssgsrgrgtgmtgmtgtdtvdvmvsvsbvsbvbtthmmftmmdnmddcrcvcrrfjfhhfjhffjllcpllmcctjtrttwmtwmwffrlrqlqzzpddsqdqqgjqgjgngwnncjnnvsnswwbzbtzzflzzqsqbsbvbmbnnjpnpnnpfpmpmnpmmjljtltssqnsqslstswtwswwjddvmmzlzqlzqzqjjlttmtrtbtmtgmtmsttrctrrsqrqvvrzrcrhhlnhllbfbtthrhdhllmwlmlgglgsgmgsmszzprpwpfprfftffpssjzjgzjzddqfqmmwqwvwlvlqqtbtwwrwttmsmppbmmpcmctcnnhssnjncnlcnctcjjrzrwrfwfcwffczztrtsrtstlsssljssmvssjzssrqqrcqqwlqwlwffsflssrrzhzzhrzzdgdppspwplpqptttvddggzszccrrnzzwwdwjddrvvwggpvgpvvhdhqddffrnngcncjcjlcchrrftrrjccrcrqqgcglcgcscmmlzmmtcmcffwfcfrcrggdmggdvvnrvnnphnngzzpdpgpspqqgrrnffmfpmffmgfmmjmzztlljlggljjcnnrqnqpnqndnffnwwbpwpjwjjlslmsmtmtjttsvsggrmmdpmmcjjswsqqwfwwrwffczfzggqvggdlldhllsdsfdsdhhmmzmjjmpjpddsccqrrjhjlhjjcnnpwnnffjwwcsszrrnmnsmnnjbnndwnnnhnwwjtwtlwtwqqbnqnbnqqfjfdjdbbwbqwqpqggbcbhhtrtqrrddpdwdlwdddzvzwvvdfdpdcdvdtdpttwwdzdzmdmqmzmnzmnmhmwmjwwshhcqcpcvvzgzdggnjnnhwnhhswwvccqrqlqggcngnmggmffblbglltlstshhrjjlvlppsqslljtjtgglvltvlvmllhrhdrrmqrmqmjjdcjjppqwwllvsvsrszslsvvghvvhmmfbfvfpfmmvdvppwggtrrjvvsbbzffbmffpqqqhnhncclzczwcwpwssrprfrsrbsbnbvnnwzwqqpsqsspmssztssstrtcczsznzvvpvttnssdjdhjddngdgvvmsszbzsbsmbbgsbgsgmmhwhghrhjhphshchgglmlvlhlbhlldwdggdsscvcbcssfbbvggvwwtstltrrwttjdtdvttlsttfhfmhhcbclbcbffqqslshlldhdqhhjwwlffrbrdbrrgcrrfmffbhhlslrslrslrlsrsnsnvvqfqnnfdfmfmttmcmcrrcmmmjttjvtvvjbjqjnnbtbnblbtlblplgltlqltlztzvvtdvvtpvvwdwfflbflfrrhbrbbmjmcjmccztzwwjzwwzwdzdnnwcclbllqgghjhlhthwrdglrmcpbmtrnrdtvjrpmzqmljzzrtpzsrhnjrsdmpnsgdhvqchcfqjqdncjqfnscwjqvszpzzfhpjljmvsqnjzmrsgsbzlvrddtdmwbwwgprlvdfflrpztdzrhtmlzrrtdmpmcprqzzwlnmfjvsrltfjgcnnfllnzmbjcbthvbffczsspmczrpgpdjmvrvfmprfmnqdcnfwwvgdrwvrbtlqmhrrjvtrmmgrlprtnzdlszgbtbwztdrmpmlfblshzcnsczlblgwzrpnlccwhmcqhssmpznbdnnqgzzmjprjttdjhmjbmgqvzblsjwmplzsthrswhsdbvtqgrfzmbpqtpqgqdqcvzlgjrtvrhvzgmcmrwdmfpdvjddsmmsnvrdgnsbsdzcbprbqchqcgnwmfsrmqtrcdhdtzztbvmpblftwqlmlmmjcjhhjlgnnhljnncvbnjhgbjrltlwscswgvqmcnssbcdrtbgnhgmpmvjwtrbrbrdbdqfrncvhdstwztwcpbjrjwzmdlwvlvmsrhghjwjnjstbcqjqtjrgcvhzjdhdgbgdlhvjmztwvhgzzggwwhhhzvtrldchztmwfjvnqnvhnwpfvzzvnlvsccmvsngzgtnttssmdmhwzlhtpnfhczsdfnrstbwvwpqmslcvpvhfzttzhsgzpbhqdtswshljpncznjhzmgvvbcllmzprhrvwljwcjpcdqmwbzvsdcgtmwnrhswsgqhwpwhbjpnhnpjvgsqcjltzrqvqfflcdcvpwnznvtqbfbtlpmtdgbbwdwncqsqnbtgfdzzqzzvjnwmzdmlgstmnjwznjqghglvmwjzlqrnddcqhgndlhlbmqdhrqgrjqztnhpzssnwmrqclmwpgbvfrvgqqvtthznsqwgndjrprbgrhcvhpzbfhdmgnhsrqjvjstbtmnltsbjfzczvjqnhtldqclsflbhvvlzjwrqqgbgpwqwpfjctqpzdqwcfstmwbzgrgrtzngljjnvtggrqcbgjwtqsdgwmfjqppnzgfsfdmlctztbhnntnntdlvrsdvnllvmpggjzspqfhzwrttwzpqrnqjhmpjnmrzrpnqzshcqgctbtflqflcrzpmnphgbbghhwzplljwngbtffwmrwggdztvtfgwldlswqvjptvbfvnbpglhgrdgcfmvrslqldmwjqvjpvwgpjddvglllvpqwvbchqsmjrncgvgmqbsbcwfbsbpqcqzjfpcdzszgmvqgqjlflpfzbsrhsrzrdbpssrjbcfhvztftlzqpsglpwhbscgwdlbgghzsbwznnbgnnsgjghmmpmmrmqmdhnflgvgprqfcbpzbcpjscvnpfrmtvzsbflmffvcfsvdsggzdqtppcjzphcqwrqtrczqmwcdmdqndzmhdpnfqsbndnvjlzrsjzmpcrfgjwccsdtzvslccwhlvzjwjgvwpsnsggmqgsjfbwmjstsgnqmtjhljvfnflnngdrqvscwlqqdsglhghczhjdvgrjcqblmncdbjvsbwgptgpvvzhcjgjnvttrgzrjnqlvfbrmpzdcbbnnrqptpzpssznbsrstdphbgdrsnrhcjwwgsncdzvqfnmnvqcmcgdgjdbqjzdrvvbvhjdfcqndmqwscmsvppclzrhgbldqtwctbdhpbbwfvwpcpsvddmrhqbhlrrmrblnmqqqbwvcwwbwprlmhtdncmjhmjgphmrrhcdrqgmcrzwsznqzpngbtsvjgglrddhjflbrhvqwmmhmqzhphwnvqwzczdvqjsnlhfqbcgddtwgnlcgbfqmzfpqmnbpvfhdhjlnwtrlmggtbfnfvmqrzjvjjvffctsrwgfcpghhnzqmwtlsfhjrvqpwqhngrhpswslsvtgnbvbmwsfwmpntfsfpshrjzvghhpvnlbmnrhltfpmqdwzfhztvhlmbnmhnbvdzbbtczvwbvwtvjghhjjrtgbrqrhmbgvssstdwztdmdsqtctghjhsnpslqttdlvndmjfnmdzwrblfjqcwptfttvlcgsvwcbmfzbdlmrtchgqlfspwznbzfjthjtfwshqgfsfdsmzsmpptzschlzjshvfwtmpszvrvlggbrgpcnqwndhjjprztdfddblhfljbvttfvhchhdfsftrhccrbncmhwpcpwfqthngcqptmvsmpcswdrdlcbqvvhwmcqqwbzlblrgfcrrndwdvlvnpjvwchzjzmgrqhzzmgqqdsdflpclpdtlhvhcthzjfbvjvzsnbvwfsnglvbnwnbgrqwpbgclhjhztttbjwvmlmmgmzncbwswncqhmcfjfnwnpbrmchhpgwngrfwgdfdqmblwlghdjvdhjftdblrtcvvgbvpmbjhfwgpmghqbqrcpgfvhtvqtlbjdblggcpjzlrhpbsqwntfhbhwwszpdlsgbpfqhvrjrhsldcgvqhqmwdfcrcmhrvvwvbrfsrrcvwzhqqvgltlnhwhdrhrdqsvmdzjwgmqdsccwhcgwltfhdfqpsltjccwsttmrc");
    //am lazy

    //Datastream_Buffer stream("bvwbjplbgvbhsrlpgdmjqwftvncz");

    std::cout << n_marker(stream, 14);

}

