#!bin/usr/perl
use 5.18.2;
use strict;
use warnings;
use Scalar::Util qw(looks_like_number);

my $filename = $ARGV[0];
if(!defined $filename) {
    print "No file given, please pass a file as the first arugument\n";
    exit;
}

open(DATA, $filename) or die "Couldn't open file $filename, $!";

my $line_number = 1;
while(<DATA>) {
    if($_ =~ m/^([0-9]*\s*[a-zA-Z]+)\s*([0-9]+(:[0-9]+(,[0-9])*)?(--([0-9]+(:[0-9]+(,[0-9]+)*)?))?)?((;([0-9]+(:[0-9]+(,[0-9])*)?(--([0-9]+(:[0-9]+(,[0-9]+)*)?))?))|(;))?\s*(\([a-zA-Z]*\))?$/) {
        print("($line_number) Valid\n");
    } else {
        print("($line_number) Invalid\n");
    }
    $line_number += 1;
}

close DATA

# say("Please enter a number (enter non-number to exit):");
# while(<STDIN>) {
#     if(!looks_like_number($_)) {
#         exit;
#     }
#     prime_partitions($_, 1, ());
#     say("Please enter a number (enter non-number to exit):");
# }

# sub is_prime {
#     my($n) = shift;

#     if($n <= 1) {
#         return 0;
#     }
#     for $a (2..($n-1)) {
#         if ($n % $a == 0) {
#             return 0;
#         }
#     }
#     return 1;
# }

# sub primes {
#     my($a) = shift;
#     my($b) = shift;
#     my($number, @out);
#     for $number ($a..$b) {
#         if(is_prime($number) == 1) {
#             @out = (@out, $number);
#         }
#     }
#     @out
# }

# sub prime_partitions {
#     my($n) = shift;
#     my($k) = shift;
#     my(@lst) = @_;

#     if($n == 0) {
#         say(join(' + ', @lst));
#     }s

#     if($n > $k) {
#         for my $p (primes(($k + 1), $n)) {
#             prime_partitions(($n - $p), $p, (@lst, $p));
#         }
#     }
# }