#!/usr/bin/env perl

use warnings;
use strict;

use constant USAGE => "Usage: $0 START END ROM <data.txt\n";
use constant OFFSET => 0x08000000;

my $start = shift or die(USAGE);
my $end = shift or die(USAGE);
my $rom = shift or die(USAGE);

hex($end) > hex($start)
    or die(USAGE);

-f $rom
    or die("Cannot find '$rom'\n");

my $first_addr = hex($start) - OFFSET;
my %labels = ($first_addr => "");

while (<>) {
    s/^\s+//;
    s/\s+$//;
    s/\s*#.*$//;

    next if /^$/;

    /^(0x[\da-fA-F]{8})\s+(\w+)$/
        or die("failed to parse line '$_'\n");

    my $addr = hex($1);
    my $label = $2;

    $labels{$addr} = $label;
}

my $last_addr = $first_addr;
for my $addr (sort keys %labels) {
    my $label = $labels{$addr};
    next if $label eq "";

    my $size = $addr - $last_addr;
    print(".incbin \"$rom\", $last_addr, $size\n") if $size;
    print("$label:\n");
    $last_addr = $addr;
}

my $size = hex($end) - OFFSET - $last_addr;
print(".incbin \"$rom\", $last_addr, $size\n");
