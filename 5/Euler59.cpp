/*
 * =====================================================================================
 *
 *       Filename:  Euler59.cpp
 *
 *    Description:  Solution to Project Euler, Problem 59
 *
 *        Version:  1.0
 *        Created:  9/2/2016 5:26:37 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange).
 *                  For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *                  A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key.
 *                  The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example,
 *                  65 XOR 42 = 107, then 107 XOR 42 = 65.
 *                  For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes.
 *                  The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
 *                  Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key.
 *                  If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message.
 *                  The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.
 *                  Your task has been made easy, as the encryption key consists of three lower case characters.
 *                  Using cipher.txt, a file containing the encrypted ASCII codes, and the knowledge that the plain text must contain common English words,
 *                  decrypt the message and find the sum of the ASCII values in the original text.
 *         Answer:  107359
 *                  While not asked in the original problem, the key is "god" and the decrypted message is:
 *                  (The Gospel of John, chapter 1) 1 In the beginning the Word already existed. He was with God, and he was God. 2 He was in the beginning with God. 3 He created everything there is. Nothing exists that he didn't make. 4 Life itself was in him, and this life gives light to everyone. 5 The light shines through the darkness, and the darkness can never extinguish it. 6 God sent John the Baptist 7 to tell everyone about the light so that everyone might believe because of his testimony. 8 John himself was not the light; he was only a witness to the light. 9 The one who is the true light, who gives light to everyone, was going to come into the world. 10 But although the world was made through him, the world didn't recognize him when he came. 11 Even in his own land and among his own people, he was not accepted. 12 But to all who believed him and accepted him, he gave the right to become children of God. 13 They are reborn! This is not a physical birth resulting from human passion or plan, this rebirth comes from God.14 So the Word became human and lived here on earth among us. He was full of unfailing love and faithfulness. And we have seen his glory, the glory of the only Son of the Father.
 * =====================================================================================
 */

#include "../helper.hpp"

// Percentage frequencies of characters a-z and space in a large corpus of English text.
// The idea is to compare the frequency of these characters in the decrypted message,
// and the message that is the least the different is probably the correct decryption.
vector<double> freqs = {
	6.550482415792841,
	1.2187227913955478,
	2.6312471550434267,
	2.9633170270486247,
	9.641983820907871,
	1.7133292982101174,
	1.6230135496241458,
	3.8630164354748753,
	6.033153565383931,
	0.14319075522289199,
	0.584919923588381,
	3.334145114873345,
	2.052310661457927,
	5.710019197576333,
	6.012435414341218,
	1.7252681764699587,
	0.10031106141034855,
	4.806753282451171,
	5.30320658449656,
	7.454606437792929,
	2.4304093395979174,
	0.8479366761897098,
	1.3724393467092453,
	0.1963782246892691,
	1.5495859506078813,
	0.09214622113166994,
	20.04567157251186 // space
};

int solve59() {
	double bestDiff = 100000;
	int result = 0;
	string line;
	vector<int> data;
	vector<int> message;
	ifstream file( "5/cipher.txt" );

	while( getline( file, line, ',' ) ) {
		try {
			data.push_back( stoi( line ) );
		} catch( const invalid_argument &ia ) {
			cerr << "Check your input file: " << "5/cipher.txt" << endl;
			throw;
		}
	}

	// 'a' is 97, 'z' is 122
	for( int a = 97; a <= 122; ++a ) {
		for( int b = 97; b <= 122; ++b ) {
			for( int c = 97; c <= 122; ++c ) {
				vector<int> key = { a, b, c };
				message.clear();

				for( int i = 0; i < data.size(); ++i ) {
					message.push_back( data[i] ^ key[i % 3] );
				}

				vector<int> counts( 27, 0 );

				for( auto && m : message ) {
					// lower case letters
					if( m >= 97 && m <= 122 ) {
						counts[m - 97]++;
						// upper case letters
					} else if( m >= 65 && m <= 90 ) {
						counts[m - 65]++;
						// space
					} else if( m == 32 ) {
						counts[26]++;
					}
				}

				double diff = 0;

				for( int i = 0; i < 27; ++i ) {
					diff += abs( freqs[i] - ( double( counts[i] ) / double( data.size() ) * 100 ) );
				}

				if( diff < bestDiff ) {
					bestDiff = diff;
					result = sum( message );
				}
			}
		}
	}

	return result;
}

