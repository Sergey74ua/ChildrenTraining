local lib = require('lib')

text = [[
p<:5w9r<7hu95a<wg95Ga9vaC/:a1au5<w95-<pGyzfJv<MAe/IfI<wyw5zaM95a<Gyua9vae/IfI<ga9y-<7yJM5-<I1fJ5MAT/
G<M5wza9vp6<g1hJMy<qa'9fua595-e/G<M1aG5gf6<>hw95-<JhaMAe/'Gh7fz<w9a<u5zg5<g5z5J<9a59A-/y<J9yzyJv<wyzAa<7a1MAT/
>zy<g5uAT<qh1v<:51AG<wpMa59A-/1fJJapz<:1a59ya<wa7MAe/y<p<'fqAz<MG5-<g5z5J<9a59A-e/MG5y<9aqaJ9Aa<7a1MAT/
G<gzh>ye<G5<w1fIa<'fM57a9vp/Mp9hzyJv<My65<u9y<w5y/qa'<q55aJMGfe<qa'<Gu5695Ga9vpe/qa'<Jza'e<qa'<5y'9ye<qa'<zrqGyT/
uh>a<9fJMfz5<:15qh5ua9vaC/y<G5M<5:pMv<pGyzfJv<MAe/IfI<wyw5zaM95a<Gyua9vae/IfI<ga9y-<7yJM5-<I1fJ5MAT/
y<Ja1u#a<qvaMJp<G<h:5a9vae/y<uzp<9ag5<G5JI1aJzy<G95Gv/y<q55aJMG5e<y<Gu5695Ga9vae/y<5y'9ve<y<Jza'Ae<y<zrq5GvT/
]]

--all(text)

text = text: gsub('<', ' ') -- 79
--find2(text, ' ')
find22(text)
text = text: gsub('/', '\n')-- 24
text = text: gsub('e', ',') -- 18
text = text: gsub('T', '.') -- 7
text = text: gsub('C', '!') -- 2

text = text: gsub('y', '�') -- 37
text = text: gsub('G', '�') -- 27
text = text: gsub('p', '�') -- 13

text = text: gsub('a', '�') -- 58
text = text: gsub('5', '�') -- 57
text = text: gsub('9', '�') -- 39
text = text: gsub('M', '�') -- 27
text = text: gsub('J', '�') -- 25
text = text: gsub('z', '�') -- 23
text = text: gsub('v', '�') -- 19
text = text: gsub('f', '�') -- 18
text = text: gsub('A', '�') -- 17
text = text: gsub('w', '�') -- 15
text = text: gsub('q', '�') -- 15
text = text: gsub('1', '�') -- 15
text = text: gsub('u', '�') -- 14
text = text: gsub("'", '�') -- 13
text = text: gsub('I', '�') -- 12
text = text: gsub('-', '�') -- 11
text = text: gsub('h', '�') -- 11
text = text: gsub('g', '�') -- 11
text = text: gsub('7', '�') -- 8
text = text: gsub(':', '�') -- 7
text = text: gsub('6', '�') -- 5
text = text: gsub('>', '�') -- 4
text = text: gsub('r', '�') -- 3
text = text: gsub('#', '�') -- 1
--text = text: gsub('', '') -- 1

print(text)

-- p G y
-- G5 mA IfI (���, ���, ���, ���, ���, ���, ���)
io.read()