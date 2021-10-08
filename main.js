const participants = [
    {
        "name": "AIT-OSS",
        "img": "https://avatars3.githubusercontent.com/u/47062438?s=400&u=ab4cb37695763efe4297b2da4b7f97cd8f6f888b&v=4",
        "title": "Organizer",
        "year": "BE - 2022",
        "linkedIn": "https://www.linkedin.com/company/open-source-software-club/",
        "github": "https://github.com/aitoss",
        "skills": ['All Open Source Technologies'],
        "description": "A student driven Open Source Community at AIT, Pune."
    },
    {
        "name": "Kumari Palak",
        "img": "https://avatars.githubusercontent.com/u/54790525?s=400&u=d29cc10e71229700b65ddbe13e0c102aa5096211&v=4",
        "year": "BE - 2023",
        "linkedIn": "https://www.linkedin.com/in/kumaripalak/",
        "github": "https://github.com/Palak-137",
    },
    {
        "name": "Snehasis Sahoo",
        "img": "https://avatars.githubusercontent.com/u/54761358?v=4",
        "year": "BE - 2023",
        "linkedIn": "https://www.linkedin.com/in/kazukilapislazuli/",
        "github": "https://github.com/kazukilapislazuli",
    },
    {
        "name": "Rohit Kumar",
        "img": "https://avatars.githubusercontent.com/u/54764235?v=4",
        "year": "BE - 2023",
        "linkedIn": "https://www.linkedin.com/in/rohitkumar-yadav/",
        "github": "https://github.com/The-Fuse",
    },
    {
        "name": "Mohammad Kaif Siddique",
        "img": "https://avatars.githubusercontent.com/MoKaif",
        "year": "BE - 2024",
        "linkedIn": "https://www.linkedin.com/in/mokaif/",
        "github": "https://github.com/MoKaif",
    },
    {
        "name": "Sachin choudhary",
        "img": "https://avatars.githubusercontent.com/u/54989437?v=4",
        "year": "BE - 2023",
        "linkedIn": "https://www.linkedin.com/in/sachin-choudhary-7037381a9/",
        "github": "https://github.com/sachin-611",
    },
    {   "name": "Ankit Gadhwal",
        "img": "https://avatars.githubusercontent.com/u/60103160?v=4",
        "year": "BE - 2023",
        "linkedIn": "https://www.linkedin.com/in/ankit-gadhwal-a9451b18b/",
        "github": "https://github.com/Ankit-123-123",
    }
]

function loadParticipants() {
    participants.forEach((participant) => {
       

        const profileCard = `
            <div class="box">
            <div class="top-bar"></div>
            <div class="top">
                <i class="fa fa-heart heart" aria-hidden="true"></i>
                <input type="checkbox" class="heart-btn" id="heart-btn-1">
               
            </div>
            <div class="content">
                <img src=${participant.img || 'https://i.ibb.co/dKnX0Kx/default-profile-pic.png'}
                    alt="">
                <strong>${participant.name}</strong>
                <p>${participant.year}</p>
            </div>
            <div class="btn">
                <a href="${participant.linkedIn}"><i class="fa fa-linkedin" aria-hidden="true"></i>LinkedIn</a>
                <a href="${participant.github}"><i class="fa fa-github" aria-hidden="true"></i>Github</a>
            </div>

        </div>
        `;

        $(".outer-div").append(profileCard);
    })
}

loadParticipants();
