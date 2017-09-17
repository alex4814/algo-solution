ranks = [str(n) for n in range(2, 10) + list('TJQKA')]
suits = 'SDCH'


class Card(object):
    def __init__(self, rank, suit):
        self.rank = ranks.index(rank)
        self.suit = suits.index(suit)
    
    def __repr__(self):
        return 'Card(%r, %r)' % (ranks[self.rank], suits[self.suit])
    
    
class Hand(object):
    def __init__(self, cards):
        self.cards = [Card(*c) for c in cards]
        self.type_ = self.sort_by_hand_type()

    def sort_by_hand_type(self):
        self.cards = sorted(self.cards, key=lambda c: c.rank, reverse=True)
        self.ranks = {c.rank for c in self.cards}
        self.suits = {c.suit for c in self.cards}
        self.diffs = {self.cards[i].rank - self.cards[i+1].rank for i in range(0, 4)}
        types = [
            'high_card', 'one_pair', 'two_pairs', 'three_of_a_kind', 'straight',
            'flush', 'full_house', 'four_of_a_kind', 'straight_flush', 'royal_flush',
        ]
        for i, type_ in reversed(list(enumerate(types))):
            func = getattr(self, 'is_' + type_, None)
            if func and func():
                return i
        assert False
        return -1
    
    def is_high_card(self):
        return len(self.ranks) == 5
    
    def is_one_pair(self):
        if len(self.ranks) != 4:
            return False
        for i in xrange(1, 5):
            if self.cards[i].rank == self.cards[i-1].rank:
                break
        for x in xrange(2):
            self.cards.insert(0, self.cards.pop(i))
        return True
    
    def is_two_pairs(self):
        if len(self.ranks) != 3:
            return False
        ranks = [c.rank for c in self.cards]
        single = -1
        for rank in self.ranks:
            if ranks.count(rank) == 1:
                if single != -1:
                    return False
                single = ranks.index(rank)
        self.cards.append(self.cards.pop(single))
        return True

    def is_three_of_a_kind(self):
        if len(self.ranks) != 3:
            return False
        found = False
        for i in xrange(2, 5):
            if self.cards[i].rank == self.cards[i-1].rank and self.cards[i-1].rank == self.cards[i-2].rank:
                found = True
                break
        if not found:
            return False
        for x in xrange(3):
            self.cards.insert(0, self.cards.pop(i))
        return True
        
    def is_straight(self):
        if len(self.ranks) != 5:
            return False
        if len(self.diffs) != 1:
            return False
        return 1 in self.diffs
        
    def is_flush(self):
        return len(self.suits) == 1
        
    def is_full_house(self):
        if len(self.ranks) != 2:
            return False
        ranks = [c.rank for c in self.cards]
        if ranks[2] != ranks[1]:
            self.cards.append(self.cards.pop(0))
            self.cards.append(self.cards.pop(0))
        return True

    def is_four_of_a_kind(self):
        if len(self.ranks) != 2:
            return False
        ranks = [c.rank for c in self.cards]
        for rank in self.ranks:
            cnt = ranks.count(rank)
            if cnt == 2 or cnt == 3:
                return False
        if ranks[1] != ranks[0]:
            self.cards.append(self.cards.pop(0))
        return True
        
    def is_straight_flush(self):
        if len(self.suits) != 1:
            return False
        return self.is_straight()
        
    def is_royal_flush(self):
        if self.cards[0].rank != ranks.index('A'):
            return False
        return self.is_straight_flush()

    def __gt__(self, other):
        if self.type_ != other.type_:
            return self.type_ > other.type_
        for i in xrange(5):
            if self.cards[i].rank == other.cards[i].rank:
                continue
            return self.cards[i].rank > other.cards[i].rank
        assert False
        return True
    
    
win = 0
with open('p054_poker.txt', 'r') as rounds:
    for round in rounds:
        round = round[:-1]
        cards = round.split(' ')
        win += Hand(cards[:5]) > Hand(cards[5:])
print win

