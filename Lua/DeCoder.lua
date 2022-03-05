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

text = text: gsub('y', 'и') -- 37
text = text: gsub('G', 'в') -- 27
text = text: gsub('p', 'я') -- 13

text = text: gsub('a', 'е') -- 58
text = text: gsub('5', 'о') -- 57
text = text: gsub('9', 'н') -- 39
text = text: gsub('M', 'т') -- 27
text = text: gsub('J', 'с') -- 25
text = text: gsub('z', 'л') -- 23
text = text: gsub('v', 'ь') -- 19
text = text: gsub('f', 'а') -- 18
text = text: gsub('A', 'ы') -- 17
text = text: gsub('w', 'м') -- 15
text = text: gsub('q', 'б') -- 15
text = text: gsub('1', 'р') -- 15
text = text: gsub('u', 'д') -- 14
text = text: gsub("'", 'з') -- 13
text = text: gsub('I', 'к') -- 12
text = text: gsub('-', 'й') -- 11
text = text: gsub('h', 'у') -- 11
text = text: gsub('g', 'г') -- 11
text = text: gsub('7', 'ч') -- 8
text = text: gsub(':', 'п') -- 7
text = text: gsub('6', 'х') -- 5
text = text: gsub('>', 'ш') -- 4
text = text: gsub('r', 'ю') -- 3
text = text: gsub('#', 'ц') -- 1
--text = text: gsub('', '') -- 1

print(text)

-- p G y
-- G5 mA IfI (еле, иди, или, как, оно, тот, тут)
io.read()